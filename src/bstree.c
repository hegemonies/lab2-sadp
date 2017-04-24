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
	b->key = malloc(strlen(key));
	if (b->key == NULL) {
		return NULL;
	}
	strcpy(b->key, key);
	b->value = value;
	b->left = NULL;
	b->right = NULL;
	return b;
}

void bstree_add(bstree *tree, char *key, int value)
{	
	bstree *parent, *node;
	if (tree == NULL) {
		return;
	}
	
	for (parent = tree; tree != NULL; ) {
		parent = tree;
		if (value < tree->value) {
			tree = tree->left;
		} else if (value > tree->value) {
			tree = tree->right;
		} else {
			return;
		}
	}
	node = bstree_create(key, value);
	if (value < tree->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
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

void printf_tree(bstree *tree)
{
    if (tree == NULL)
    {
       return;
    }
    printf_tree(tree->left);
    printf("%d : %s", tree->value, tree->key);
    printf_tree(tree->right);
}

int insert(struct tree * search_tree, int item)
{
	struct node * search_node, **new;

	new = &search_tree->root;
	search_node = search_tree->root;

	for(;;)
	{
		if(search_node == NULL)
		{
			search_node = *new = malloc(sizeof * search_node);
			if(search_node != NULL)
			{
				search_node->data = item;
				search_node->left = search_node->right=NULL;
				search_tree->count++;
				return 1;
			}
			else return 0;
		}
		else if(item == search_node->data) return 2;
else if(item > search_node->data)
{
new = &search_node->right;
			search_node = search_node->right;
		}
		else
		{
			new = &search_node->left;
			search_node = search_node->left;
		}
	}
}