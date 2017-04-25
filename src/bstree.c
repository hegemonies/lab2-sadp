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
	/*
	b->key = malloc(strlen(key) + 1);
	if (b->key == NULL) {
		return NULL;
	}
	*/
	b->key = key;
	//strcpy(b->key, key);
	b->value = value;
	b->left = NULL;
	b->right = NULL;
	return b;
}
/*
void bstree_add(bstree *tree, char *key, int value)
{	
	if (tree == NULL) {
		return;
	}
	bstree *parent;
	for (parent = tree; parent != NULL; ) {
		//parent = tree;
		if (value < tree->value) {
			parent = tree->left;
		} else if (value > tree->value) {
			parent = tree->right;
		} else {
			return;
		}
	}
	bstree *node = bstree_create(key, value);
	parent = node;
	
	if (value < tree->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
	
}
*/

bstree *bstree_add(bstree *tree, char *key, int value)
{
	if (tree == NULL) {
		tree = bstree_create(key, value);
	} else if (value < tree->value) {
		tree->left = bstree_add(tree->left, key, value);
	} else {
		tree->right = bstree_add(tree->right, key, value);
	}
	return tree;
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	while (tree != NULL) {
		if (strcmp(tree->key, key) == 0) {
			return tree;
		} else if (strcmp(tree->key, key) < 0) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}

bstree *bstree_min(bstree *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=  NULL) {
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
