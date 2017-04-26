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
	if (tree == NULL) {
		tree = bstree_create(key, value);
	} else if (strcmp(key, tree->key) < 0) {
		tree->left = bstree_add(tree->left, key, value);
	} else {
		tree->right = bstree_add(tree->right, key, value);
	}
	return tree;
}

bstree *bstree_search(bstree *node, char *key)
{
	while (node) {
		char *tmp = malloc(strlen(key) + 1);
		strcpy(tmp, key);
		tmp[(strlen(key))] = '\n';
		printf("%s -- %s", key, node->key);
		
		if (strcmp(tmp, node->key) < 0) {
			printf("Прошел в лево\n");
			free(tmp);
			node = node->left;
			continue;
		}
		if (strcmp(tmp, node->key) > 0) {
			printf("Прошел в право\n");
			free(tmp);
			node = node->right;
			continue;
		}
		if (strcmp(tmp, node->key) == 0) {
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
		printf("Иду на лево\n");
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=  NULL) {
		printf("Иду на право\n");
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
    printf("Пошел на право\n");
    print_tree(tree->right);
    printf("Пошел на лево\n");
    print_tree(tree->left);
    //printf("%d : %s", tree->value, tree->key);
    
    //print_tree(tree->right);
}
