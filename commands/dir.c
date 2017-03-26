#ifdef _WIN32
#elif defined __linux__
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif

char* itoa(int i) {
	size_t length = snprintf( NULL, 0, "%d", i );
	char* str = malloc(sizeof(char) * (length + 1));
	snprintf( str, length + 1, "%d", i );
	return str;
}

void dir_execute(void* terminal, void* self, char* arguments) {
	#ifdef _WIN32
	#elif defined __linux__
	printf(" Volume in drive ? is ?\n");
	printf(" Volume Serial Number is ?\n");
	printf("\n");
	printf(" Directory of F:\\\n");
	
	DIR* dir = opendir("/");
	struct dirent* dp;
	struct stat file_stat;
	
	size_t files = 0;
	size_t directories = 0;
	
	size_t total_size = 0;
	
	while((dp = readdir(dir)) != NULL) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) {
		} else {
			char absolute_path[strlen(dp->d_name) + 1];
			strcpy(absolute_path, "/");
			strcat(absolute_path, dp->d_name);
			
			if(stat(absolute_path, &file_stat) != 0) {
				printf("ERROR!\n");
				return;
			}
			
			char date[18]; // 00/00/0000
			time_t timestamp = (time_t) file_stat.st_ctime;
			struct tm* tm_info = localtime(&timestamp);
			
			strftime(date, 18, "%d/%m/%Y  %I:%M", tm_info);
			printf("%s %s %s\n", date, left_space(itoa(file_stat.st_size), 17), dp->d_name);
			
			if(S_ISREG(file_stat.st_mode)) {
				files++;
			} else {
				directories++;
			}
			total_size += file_stat.st_size;
		}
	}
	
	//               7
	//     5,623,325
	printf("%s File(s) %s bytes\n", left_space(itoa(files), 16), left_space(itoa(total_size), 14));
	printf("%s  Dir(s) %s bytes free\n", left_space(itoa(directories), 16), left_space(itoa(total_size), 14));
	#endif
}