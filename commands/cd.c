#ifdef _WIN32
#elif defined __linux__
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#endif

void cd_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	Terminal_navigate(terminal, arguments);
}