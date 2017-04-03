#include <stdio.h>
#include <string.h>
#include "bstree.h"

bstree *bstree_create(char *key, int value)
{
	bstree *b = malloc(sizeof(bstree));
	if (b == NULL) {
		return NULL;
	}
	b->key = malloc(strlen(key));
	if (b->key == NULL) {
		return NULL;
	}
	strcpy(b->key, key);
	b->value = value;
	b->parent = NULL;
	b->left = NULL;
	b->right = NULL;
	return b;
}
/*
void bstree_add(bstree *tree, char *key, int value)
{
	bstree *a = bstree_create(key, value);
	if (a == NULL) {
		return;
	}
	a->parent = &tree;
	if (tree->left == NULL) {
		tree->left = &a;
	} else if (tree->right == NULL) {
		tree->right = &a;
	} else {
		return;
	}
}
*/

void bstree_add(bstree *tree, char *key, int value)
{
	bstree *parent = NULL;
	while (tree == NULL) {
		parent = tree;
		if (value < tree->value) {
			tree = tree->left;
		} else if (value > tree->value) {
			tree = tree->right;
		} else {
			return;
		}
	}
	bstree *node = bstree_create(key, value);
	if (value < parent->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

bstree *bstree_lookup(bstree *tree, char *key)
{

}

bstree *bstree_min(bstree *tree);

bstree *bstree_max(bstree *tree);