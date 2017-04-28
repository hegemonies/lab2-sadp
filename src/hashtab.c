#include <string.h>
#include <stdlib.h>
#include "hashtab.h"
#define SIZE_ARR 5

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
	for (int i = 0; i < SIZE_ARR; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	int index = hashtab_hash(key);
	listnode *node;
	node = malloc(sizeof(listnode*));
	hashtab[index] = malloc(sizeof(listnode));
	if (hashtab[index] != NULL) {
		hashtab[index]->key = key;
		hashtab[index]->value = value;
		/*
		while (hashtab[index] != NULL) {
			index++;
			if (index >= SIZE_ARR) {
				return;
			}
		}
		*/
		hashtab[index]->next = NULL;
		return;
	}
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
	int index = hashtab_hash(key);
	listnode *p;
	listnode *prev = NULL;
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL) {
				hashtab[index] = p->next;
			} else {
				prev->next = p->next;
			}
			free(p);
			return;
		}
		prev = p;
	}
}
