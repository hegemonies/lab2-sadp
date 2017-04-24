#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bstree {
	int value;
	char *key;
	struct bstree *parent;
	struct bstree *left;
	struct bstree *right;
};

typedef struct bstree bstree_t;

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
	if (value < tree->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

int main(void)
{
	char *str[2];
	str[1] = "Hello";
	str[2] = "WOW";
	bstree_t *root;
	root = bstree_create(str[1], 1);
	printf("ROOT OF TREE: %d , %s", root->value, root->key);
	//bstree_add(root, str[2], 2);
	//printf("ROOT OF TREE: %d , %s", root->right->value, root->right->key);
}


