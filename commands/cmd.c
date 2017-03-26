#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#elif defined __linux__
#include <sys/utsname.h>
#endif

void cmd_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	#ifdef _WIN32
	#elif defined __linux__
	struct utsname os_stat;
	uname(&os_stat);
	printf("%s [Version %s]\n", os_stat.version, os_stat.release);
	printf("GNU General Public License (version 3)\n");
	#endif
	
	char* line;
	size_t length;
	char character;
	
	while(1) {
		line = calloc(1, 1);
		length = 0;
		character = NULL;
		
		if(echo_status) {
			printf("\n%s> ", Path_to_string(terminal->first_path));
		}
		while((character = getchar()) != '\n') {
			line = realloc(line, length+1);
			line[length] = character;
			length++;
		}
		
		Terminal_execute_command(terminal, line);
		
		free(line);
	}
}