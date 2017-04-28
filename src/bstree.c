#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bstree.h"

bstree *bstree_create(char *key, int value)
{
	bstree *b = malloc(sizeof(bstree));
	if (b == NULL) {
		return NULL;
	}
	b->key = key;
	b->value = value;
	b->left = NULL;
	b->right = NULL;
	return b;
}


bstree *bstree_add(bstree *tree, char *key, int value)
{
	//printf("%s", key);
	if (tree == NULL) {
		//printf("СОЗДАЮ\n");
		tree = bstree_create(key, value);
	} else if (strcmp(key, tree->key) < 0) {
		//printf("СРАВНИВАЮ\n%s : %s", key, tree->key);
		//printf("ПЕРЕХОД ВЛЕВО\n");
		tree->left = bstree_add(tree->left, key, value);
	} else if (strcmp(key, tree->key) > 0){
		//printf("СРАВНИВАЮ\n%s : %s", key, tree->key);
		//printf("ПЕРЕХОД ВПРАВО\n");
		tree->right = bstree_add(tree->right, key, value);
	}
	//printf("ВОЗВРАЩАЮСЬ\n");
	return tree;
}

bstree *bstree_search(bstree *node, char *key)
{
	while (node) {
		char *tmp = malloc(strlen(key) + 1);
		strcpy(tmp, key);
		tmp[(strlen(key))] = '\0';
		//printf("%s -- %s", tmp, node->key);
		int num = strcmp(tmp, node->key);
		if (num < 0) {
			//printf("Прошел в лево\n");
			free(tmp);
			node = node->left;
			continue;
		}
		if (num > 0) {
			//printf("Прошел в право\n");
			free(tmp);
			node = node->right;
			continue;
		}
		if (num == 0) {
			free(tmp);
			return node;
		}
	}
	return NULL;
}

bstree *bstree_min(bstree *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left != NULL) {
		//printf("Иду на лево\n");
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=  NULL) {
		//printf("Иду на право\n");
		tree = tree->right;
	}
	return tree;
}

void print_tree(bstree *tree)
{
    if (tree == NULL)
    {
    	return;
    }
    print_tree(tree->left);
    printf("%d : %s", tree->value, tree->key);
    print_tree(tree->right);
}
