#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bstree.h"
//#include <time.h>

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

/*
void mix(char **str, const int n)
{
	//srand(time(0));
	int tmp = n - 1;
	for (int i = 0; tmp > 0; i++) {
		int rand_int = getrand(0, tmp);
		char *buf = malloc(strlen(str[tmp]) + 1);
		strcpy(buf, str[tmp]);
		strcpy(str[tmp], str[rand_int]);
		strcpy(str[rand_int], buf);
		tmp--;
		free(buf);
	}
}
*/
/*
void str_to_bstree(char **str, const int num, bstree *root) 
{
	for (int i = 1; i < num; i++) {
		bstree_add(root, str[i], getrand(0, 100000));
	}
}
*/
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
	FILE *text = fopen("war_and_peace.txt", "r");
	//printf("%p\n", text);
	char *buf = NULL;
	int num = 50000;
	char **str = malloc(num * sizeof(char*));

	size_t len = 0;
	for (int i = 0; getline(&buf, &len, text) != -1; i++) {
		str[i] = (char*) malloc(strlen(buf) + 1);
		strcpy(str[i], buf);
		free(buf);
		len = 0;
		buf = 0;
	}
	//free(buf);
	//printf_array_str(str, num);
	mix(str, num);
	//printf_array_str(str, num);
	//
	//srand(time(0));
	bstree *root;
	root = bstree_create(str[getrand(0, 50000)], getrand(0, 50000));
	//printf("ROOT OF TREE: %d , %s", root->value, root->key);
	//bstree_add(root, str[1], getrand(1, 10000));
	//str_to_bstree(str, num, root);
	//bstree **tree_arr = malloc(sizeof(bstree*) * 10);
	for (int i = 1; i < num; i++) {
		//tree_arr[i] = malloc(sizeof(bstree));
		//tree_arr[i] = bstree_add(root, str[i], getrand(1, 10));
		bstree_add(root, str[i], getrand(1, 50000));
	}
	print_tree(root);
	//bstree *tmp = root->right;
	/*
	for (int i = 0; i < num; i++) {
		printf("%d : %s", (tree_arr[i])->value, (tree_arr[i])->key);
	}
	*/
	free(root);

	free_str(str, num);
	free(str);
	//printf("%p\n", text);
	fclose(text);
	return 0;
}
