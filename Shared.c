int echo_status = 1;

// STRING MANIPULATION FUNCTIONS
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

// NUMBER TO STRING FUNCTIONS
char* itoa(int i) {
	size_t length = snprintf( NULL, 0, "%d", i );
	char* str = malloc(sizeof(char) * (length + 1));
	snprintf( str, length + 1, "%d", i );
	return str;
}

char* ltoa(long i) {
	size_t length = snprintf( NULL, 0, "%lu", i );
	char* str = malloc(sizeof(char) * (length + 1));
	snprintf( str, length + 1, "%lu", i );
	return str;
}