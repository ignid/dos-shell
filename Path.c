#include "Path.h"

Path* Path_create(char* name) {
	Path* path = (Path*)malloc(sizeof(Path));
	path->name = name;
	path->next = NULL;
	path->previous = NULL;
	return path;
}

void Path_destroy(Path* self) {
	free(self);
}

char* Path_to_string(Path* self) {
	char* string = malloc(strlen(self->name) * sizeof(char));
	strcpy(string, self->name);
	
	Path* current = self;
	while(current->next != NULL) {
		current = current->next;
		string = realloc(string, (strlen(current->name)+1)*sizeof(char));
		strcat(string, current->name);
		strcat(string, "/");
	}
	
	return string;
}