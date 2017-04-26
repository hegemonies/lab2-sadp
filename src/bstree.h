#ifndef BSTREE_H
#define BSTREE_H

typedef struct bstree {
	int value;
	char *key;
	struct bstree *left;
	struct bstree *right;
} bstree;

//typedef struct bstree bstree_t;

bstree *bstree_create(char *key, int value);

bstree *bstree_add(bstree *tree, char *key, int value);

//bstree *bstree_lookup(bstree *tree, char *key);

bstree *bstree_search(bstree *node, char *key);

bstree *bstree_min(bstree *tree);

bstree *bstree_max(bstree *tree);

void print_tree(bstree *tree);

#endif