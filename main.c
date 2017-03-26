#include <stdio.h>
#include "Shared.c"
#include "Terminal.c"
#include "commands/cmd.c"
#include "commands/dir.c"
#include "commands/echo.c"
#include "commands/exit.c"
#include "commands/cd.c"

int main(int argc, char* argv[]) {
	Terminal* terminal = Terminal_create();
	
	Terminal_add_command(terminal, Command_create("dir", dir_execute));
	Terminal_add_command(terminal, Command_create("exit", exit_execute));
	Terminal_add_command(terminal, Command_create("echo", echo_execute));
	Terminal_add_command(terminal, Command_create("cd", cd_execute));
	Terminal_add_command(terminal, Command_create("cmd", cmd_execute));
	
	Terminal_execute_command(terminal, "cmd");
	
	return 0;
}