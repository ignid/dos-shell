#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#elif defined __linux__
#include <sys/utsname.h>
#endif

void cmd_execute(void* terminal, void* self, char* arguments) {
	#ifdef _WIN32
	#elif defined __linux__
	struct utsname os_stat;
	uname(&os_stat);
	printf("%s [Version %s]\n", os_stat.version, os_stat.release);
	printf("GNU General Public License (version 3)\n");
	#endif
	
	char* line;
	char* command;
	char* args;
	size_t command_length, length;
	char character;
	
	while(1) {
		line = calloc(1, sizeof(char));
		command = NULL;
		args = NULL;
		command_length = 0;
		length = 0;
		
		if(echo_status) {
			printf("\nC:\\> ");
		}
		while((character = getchar()) != '\n') {
			line = realloc(line, sizeof(char)*(length+1));
			line[length] = character;
			length++;
			if(isspace(character) && !command_length) {
				command = malloc(sizeof(char) * length);
				command_length = length;
				strncpy(command, line, length);
			}
		}
		
		if(!command_length) {
			command = calloc(length, sizeof(char));
			command_length = length;
			strncpy(command, line, length);
		}
		
		if(length != command_length) {
			args = malloc(sizeof(char) * (length));
			strncpy(args, line + command_length, length);
			Terminal_execute_command((Terminal*)terminal, command, args, command_length - 1);
			
			free(args);
		} else {
			Terminal_execute_command((Terminal*)terminal, command, "", length);
		}
		
		free(line);
		free(command);
	}
}