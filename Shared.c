int echo_status = 1;

// STRING TRIM COURTESY OF jkramer
// https://stackoverflow.com/a/123724
void strtrim(char* string) {
	char * p = string;
	int l = strlen(p);

	while(isspace(p[l - 1])) p[--l] = 0;
	while(* p && isspace(* p)) ++p, --l;

	memmove(string, p, l + 1);
}