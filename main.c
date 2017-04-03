#include <stdio.h>
#include <string.h>

int main()
{
	FILE *text = fopen("war_and_peace.txt", "r");
	uint32_t mem = 51179;
	char *key = malloc(sizeof(*char) * mem);
	char buffer[25];
	for (int i = 0; !feof(text); i++) {
		fscanf(text, "%s", buffer);
		key[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
		strncpy(key[i], buffer, strlen(buffer) + 1);
		bstree *a = bstree_create(key[i], i);
		bstree_add(a, key[i], i);
	}
	fclose(text);
	return 0;
}
