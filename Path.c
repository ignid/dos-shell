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
	size_t length = strlen(self->name);
	Path* current = self->next;
	while(current != NULL) {
		length += strlen(current->name) + 1;
		current = current->next;
	}
	
	char* string = malloc(length);
	strcpy(string, self->name);
	current = self;
	while(current->next != NULL) {
		current = current->next;
		strcat(string, current->name);
		strcat(string, "/");
	}
	string[length] = '\0';
	
	return string;
}