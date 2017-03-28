void cd_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	if(strlen(arguments) == 0) {
		printw("%s\n", Path_to_string(terminal->first_path));
	} else {
		Terminal_navigate(terminal, arguments);
	}
}