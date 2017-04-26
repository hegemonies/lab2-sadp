#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bstree.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void mix(char **str, const int n)
{
	int tmp = n - 1;
	for (int i = 0; tmp > 0; i++) {
		int rand_i = getrand(0 , tmp - 1);
		char *buf = str[tmp];
		str[tmp] = str[rand_i];
		str[rand_i] = buf;
		tmp--;
	}
}

void printf_array_str(char **str, int num)
{
	for (int i = 0; i < num; i++) {
		printf("%d: %s", i + 1, str[i]);
	}
	printf("\n\n");
}

void free_str(char **str, int num)
{
	for (int i = 0; i < num; i++) {
		free(str[i]);
	}
}

int main()
{
	FILE *text = fopen("text.txt", "r");
	char buf[512];
	int num = 20;
	char **str = malloc(num * sizeof(char*));
	for (int i = 0; fgets(buf, 512, text) != NULL; i++) {
		str[i] = (char*) malloc(strlen(buf) + 1);
		strcpy(str[i], buf);
	}
	printf("\n\n");
	printf_array_str(str, num);
	printf("MIX\n");
	mix(str, num);
	printf_array_str(str, num);
	bstree *root;
	root = bstree_create(str[getrand(0, num)], getrand(0, num));
	printf("ROOT - %d : %s\n", root->value, root->key);

	for (int i = 1; i < num; i++) {
		
		bstree_add(root, str[i], getrand(1, num));
	}
	print_tree(root);
	printf("\n\n");
	char *tmp_key = "морской";
	bstree *example = bstree_search(root, tmp_key);
	if (example != NULL) {
		printf("НАШЕЛ -\t%d : %s", example->value, example->key);
	}

	printf("\n\n");
	bstree *min_node = bstree_min(root);
	if (min_node != NULL) {
		printf("Минимальный узел -\t%d : %s", min_node->value, min_node->key);
	}

	bstree *max_node = bstree_max(root);
	if (max_node != NULL) {
		printf("Максимальный узел -\t%d : %s", max_node->value, max_node->key);
	}

	free(root);
	free_str(str, num);
	free(str);
	fclose(text);
	return 0;
}
