#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "Terminal.h"
#define INITIAL_COMMANDS 10

Terminal* Terminal_create() {
	Terminal* terminal = (Terminal*)malloc(sizeof(Terminal));
	terminal->commands = (Command**)malloc(sizeof(Command*) * INITIAL_COMMANDS);
	terminal->length = 0;
	terminal->capacity = INITIAL_COMMANDS;
	return terminal;
}

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

void Terminal_execute_command(Terminal* self, char* name, char* arguments, size_t name_length) {
	size_t i;
	for(i = 0; i < self->length; i++){
		//printf("%s %s %i\n",self->commands[i]->name, name, strncmp(self->commands[i]->name, name, name_length));
		if(strncmp(self->commands[i]->name, name, name_length) == 0) {
			self->commands[i]->execute(self, self->commands[i], arguments);
			return;
		}
	}
	printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n", name);
}