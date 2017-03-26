void echo_execute(void* terminal, void* self, char* arguments) {
	if(strcmp(arguments, "on") == 0) {
		printf("ECHO is on.\n");
		echo_status = 1;
		return;
	} else if(strcmp(arguments, "off") == 0) {
		echo_status = 0;
		return;
	}
	
	printf("%s", arguments);
}