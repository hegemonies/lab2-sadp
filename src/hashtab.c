#include "hashtab.h"
#define SIZE_ARR 128

int hashtab_hash(char *key)
{
	int hash = 0;
	for (int i = 0; i < strlen(key); i++) {
		hash = (hash * 127 + key[i]) % SIZE_ARR;
	}
	return hash;
}

void hashtab_init(struct listnode **hashtab)
{
	//malloc(sizeof(listnode*) * 128);
	for (int i = 0; i < SIZE_ARR; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	int index = hashtab_hash(key);
	listnode *node = malloc(sizeof(node*));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		while (hashtab[index] != NULL) {
			index++;
			if (index >= SIZE_ARR) {
				return;
			}
		}
		node->next = hashtab[index];
		hashtab[index] = node;
	}
	free(node);
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
	int index = hashtab_hash(key);
	listnode *node;
	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
	
}