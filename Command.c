#include "Command.h"

Command* Command_create(char* name, void (*execute)(void* terminal, void* self, char* arguments)) {
	Command* command = (Command*)malloc(sizeof(Command));
	command->name = name;
	command->execute = execute;
	return command;
}