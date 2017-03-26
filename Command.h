typedef struct {
	
	char* name;
	void (*execute)(void* terminal, void* self, char* arguments);
	
} Command;

Command* Command_create(char* name, void (*execute)(void* terminal, void* self, char* arguments));