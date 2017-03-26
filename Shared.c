int echo_status = 1;

#ifdef _WIN32
char* path_name = "C:\\";
char* actual_path_name = "C:\\";
#elif defined __linux__
char* path_name = "C:\\";
char* actual_path_name = "/";
#endif

char* left_space (char* string, size_t max) {
	size_t string_len = strlen(string);
	size_t space_len = max - string_len;
	char* spaced = malloc(sizeof(char) * (max + 1));
	size_t i;
	for(i = 0; i < space_len; i++) {
		spaced[i] = ' ';
	}
	strcat(spaced, string);
	spaced[max + 1] = '\0';
	return spaced;
}