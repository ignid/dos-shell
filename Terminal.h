#include <stddef.h>
#include "Command.c"

typedef struct {
	
	Command** commands;
	size_t length;
	size_t capacity;
	
} Terminal;

Terminal* Terminal_create();
int Terminal_add_command(Terminal* self, Command* command);
void Terminal_execute_command(Terminal* self, char* name, char* arguments, size_t name_length);