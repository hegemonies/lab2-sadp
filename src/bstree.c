#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bstree.h"

bstree_t *bstree_create(char *key, int value)
{
	bstree_t *b = malloc(sizeof(bstree_t));
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

void bstree_add(bstree_t *tree, char *key, int value)
{
	bstree_t *parent;
	if (tree == NULL) {
		return;
	}
	for (parent = tree; tree != NULL; ) {
		parent = tree;
		if (value < tree->value) {
			tree = tree->left;
		} else if (value > tree->value) {
			tree = tree->right;
		} else
			return;
	}
	bstree_t *node = bstree_create(key, value);
	if (value < parent->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

bstree_t *bstree_lookup(bstree_t *tree, int key)
{
	while (tree != NULL) {
		if (key == tree->value) {
			return tree;
		} else if (key < tree->value) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}
/*
bstree *bstree_min(bstree *tree);

bstree *bstree_max(bstree *tree);
*/
