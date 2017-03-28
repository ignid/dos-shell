#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

void cmd_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	struct utsname os_stat;
	uname(&os_stat);
	printw("%s [Version %s]\n", os_stat.version, os_stat.release);
	printw("GNU General Public License (version 3)\n");
	refresh();
	
	char* line;
	size_t length;
	
	while(1) {
		line = calloc(1,1);
		length = 0;
		if(echo_status) {
			printw("\n%s> ", Path_to_string(terminal->first_path));
			refresh();
		}
		getstr(line);
		Terminal_execute_command(terminal, line);
		free(line);
	}
}