#include <stdlib.h>

void exit_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	endwin();
	exit(EXIT_SUCCESS);
}