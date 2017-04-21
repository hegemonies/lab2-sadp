#ifndef BSTREE_H
#define BSTREE_H

struct bstree {
	int value;
	char *key;
	struct bstree *parent;
	struct bstree *left;
	struct bstree *right;
};

typedef struct bstree bstree_t;

bstree_t *bstree_create(char *key, int value);

void bstree_add(bstree_t *tree, char *key, int value);

bstree_t *bstree_lookup(bstree_t *tree, int key);

bstree_t *bstree_min(bstree_t *tree);

bstree_t *bstree_max(bstree_t *tree);

#endif
