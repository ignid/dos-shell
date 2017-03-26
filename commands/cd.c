void cd_execute(struct Terminal* terminal, struct Command* self, char* arguments) {
	Terminal_navigate(terminal, arguments);
}