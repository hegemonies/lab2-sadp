#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "bstree.h"
#include "hashtab.h"
#include <time.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

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
	//FILE *f = fopen("total.txt", "w");
	for (int i = 0; i < num; i++) {
		printf("%p : %d : %s", str[i], i + 1, str[i]);
	}
	//printf("\n\n");
	//fclose(f);
}

void free_str(char **str, int num)
{
	for (int i = 0; i < num; i++) {
		free(str[i]);
	}
}

int main()
{
	srand(time(0));
	FILE *text = fopen("text.txt", "r");
	char buf[512];
	int num = 5;
	char **str = malloc(num * sizeof(char*));
	for (int i = 0; fgets(buf, 512, text) != NULL; i++) {
		str[i] = (char*) malloc(strlen(buf) + 1);
		strcpy(str[i], buf);
	}
	//
	printf("\n\nORIGINAL\n");
	printf_array_str(str, num);
	printf("MIX\n");
	mix(str, num);
	printf_array_str(str, num);
	//ДЕЕЕЕРЕЕЕЕВОООООО
	/*
	bstree *root;
	root = bstree_create(str[getrand(0, num)], getrand(0, num));
	printf("ROOT - %d : %s\n", root->value, root->key);

	for (int i = 1; i < num; i++) {
		bstree_add(root, str[i], getrand(1, num));
		if ((i + 1) % 10000 == 0) {
			printf("%d\n", i + 1);
			char *g = str[getrand(0, i - 10)];
			printf("%s", g);
			bstree *node_search;

			double t = wtime();
			node_search = bstree_search(root, g);
			t = wtime() - t;

			printf("%f\n", t);
			if (node_search != NULL) {
				printf("\nНАШЕЛ -\t%d : %s", node_search->value, node_search->key);
			}
		}
	}
	//
	
	//print_tree(root);
	printf("\n\n");
	//char *tmp_key = "морской";
	bstree *example;
	float t = wtime();
	example = bstree_search(root, "чистым\n");
	t = wtime() - t;
	printf("\n%.4f", t);
	if (example != NULL) {
		printf("\nНАШЕЛ -\t%d : %s", example->value, example->key);
	}
	//
	printf("\n\n");
	bstree *min_node = bstree_min(root);
	if (min_node != NULL) {
		printf("Минимальный узел -\t%d : %s", min_node->value, min_node->key);
	}
	//
	bstree *max_node = bstree_max(root);
	if (max_node != NULL) {
		printf("Максимальный узел -\t%d : %s", max_node->value, max_node->key);
	}
	*/
	//ХЭЭЭЭЭЭЩ ТАБЛИИИИИИИЦАААА
	
	listnode **hashtab = malloc(5 * sizeof(listnode*));
	hashtab_init(hashtab);
	//hashtab_add(hashtab, str[getrand(0, num)], getrand(0, num));
	printf("\n\n");
	
	for (int i = 0; i < num; i++) {
	/*
		printf("\n%d\n", strlen(str[i]));
		for (int j = 0; j < strlen(str[i]); j++) {
			printf("%c", str[j]);
		}
		*/
		int v = getrand(0, num);
		hashtab_add(hashtab, str[i], v);
	}
	for (int i = 0; i < 5; i++) {
		if (hashtab[i] != NULL) {
			//printf("%d *&* %s", hashtab[i]->value, hashtab[i]->key);
			listnode *tmp_node = hashtab[i];
			while (tmp_node != NULL) {
				printf("%d *&* %s", tmp_node->value, tmp_node->key);
				tmp_node = tmp_node->next;
			}
		} else {
			printf("NULL\n");
		}
	}
	
	listnode *search_node = hashtab_lookup(hashtab, "морской\n");
	if (search_node != NULL) {
		printf("\nSearch:\n%d : %s", search_node->value, search_node->key);
	}
	
	hashtab_delete(hashtab, "морской\n");
	
	listnode *search_node_1 = hashtab_lookup(hashtab, "морской\n");
	if (search_node_1 != NULL) {
		printf("%d : %s", search_node_1->value, search_node_1->key);
	}
	//
	//free(root);
	//free_str(str, num);
	//free(str);
	
	fclose(text);
	return 0;
}
