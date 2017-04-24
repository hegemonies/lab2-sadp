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
		if (strcmp(tree->key, key) < 0) {
			tree = tree->left;
		} else if (strcmp(tree->key, key) > 0) {
			tree = tree->right;
		} else
			return;
	}
	bstree_t *node = bstree_create(key, value);
	if (strcmp(parent->key, key) < 0) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

bstree_t *bstree_lookup(bstree_t *tree, char *key)
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

bstree_t *bstree_min(bstree_t *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

bstree_t *bstree_max(bstree_t *tree) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=  NULL) {
		tree = tree->right;
	}
	return tree;
}