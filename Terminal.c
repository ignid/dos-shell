#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <errno.h>
#include "Terminal.h"
#define INITIAL_COMMANDS 10
#define DEFAULT_PATH_NAME "/"

Terminal* Terminal_create() {
	Terminal* terminal = (Terminal*)malloc(sizeof(Terminal));
	
	terminal->commands = (Command**)malloc(sizeof(Command*) * INITIAL_COMMANDS);
	terminal->length = 0;
	terminal->capacity = INITIAL_COMMANDS;
	
	terminal->first_path = Path_create(DEFAULT_PATH_NAME);
	terminal->last_path = terminal->first_path;
	
	return terminal;
}

// Command calls
int Terminal_add_command(Terminal* self, Command* command) {
	if(self->length == self->capacity) {
		void* tmp_commands = realloc(self->commands, (self->length + 1)*sizeof(Command*));
		if(tmp_commands == NULL) {
			printf("REALLOC COMMANDS FAILED! SAD!");
			return 0;
		} else {
			self->commands = tmp_commands;
		}
	}
	self->commands[self->length] = command;
	self->length++;
	self->capacity++;
	return self->length;
}

void Terminal_execute_command(Terminal* self, char* line) {
	if(strcmp(line, "") == 0) return;
	strtrim(line);
	char* running = strdup(line);
	char* command = strsep(&running, " ");
	
	size_t length = strlen(line) - strlen(command);
	char* arguments = malloc(length);
	strncpy(arguments, line + strlen(command) + 1, length); // +1 for space
	arguments[length] = '\0';
	
	size_t i;
	for(i = 0; i < self->length; i++){
		if(strcmp(self->commands[i]->name, command) == 0) {
			self->commands[i]->execute(self, self->commands[i], arguments);
			return;
		}
	}
	printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n", command);
}

// Path manipulations
void Terminal_navigate(Terminal* self, char* path_name) {
	char* path_token = strtok(path_name, "/");
	if(path_token == NULL) {
		Terminal_navigate_folder(self, path_name);
	} else {
		while(path_token != NULL) {
			Terminal_navigate_folder(self, path_token);
			path_token = strtok(NULL, "/");
		}
	}
}

void Terminal_navigate_folder(Terminal* self, char* path_name) {
	if (strlen(path_name) == 0 || strcmp(path_name, ".") == 0) {
		return;
	} else if(strcmp(path_name, "..") == 0) {
		Path* previous = self->last_path->previous;
		Path* current = self->last_path;
		if(previous == NULL) {
			return;
		}
		self->last_path = previous;
		self->last_path->next = NULL;
		free(current);
	} else {
		Path* path = Path_create(path_name);
		
		char* last_path_string = Terminal_get_path(self);
		char path_string[strlen(last_path_string) + strlen(path->name)];
		strcpy(path_string, last_path_string);
		strcat(path_string, path->name);
		
		struct stat fs_stat;
		if(stat(path_string, &fs_stat) == -1) {
			if(errno == 2) {
				printf("The system cannot find the path specified.\n");
			} else {
				printf("ERRNO %i\n", errno);
			}
			free(path);
		} else if(S_ISREG(fs_stat.st_mode)) {
			printf("The directory name is invalid.\n");
			free(path);
		} else {
			self->last_path->next = path;
			path->previous = self->last_path;
			self->last_path = path;
		}
	}
}

char* Terminal_get_path(Terminal* self) {
	return Path_to_string(self->first_path);
}