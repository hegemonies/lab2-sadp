#include <stdio.h>
#include <string.h>
#include "bstree.h"

bstree *bstree_create(char *value, int key)
{
	bstree *b = malloc(sizeof(bstree));
	b->value = malloc(strlen(value));
	strcpy(b->value, value);
	b->key = key;
	b->left = NULL;
	b->right = NULL;
	return b;
}

void bstree_add(bstree *tree, char *key, int value)
{
	
}

bstree *bstree_lookup(bstree *tree, char *key);

bstree *bstree_min(bstree *tree);

bstree *bstree_max(bstree *tree);
