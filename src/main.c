#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "bstree.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void print_arr(int arr[], int mem)
{
	for (int i = 0; i < mem; i++) {
		printf("%d\n", arr[i]);
	}
}

void write_to_arr(int arr[], int mem)
{
	for (int i = 0; i < mem; i++) {
		arr[i] = getrand(0, 19);
	}
}

void mix(int arr[], int mem)
{
	for (int i = 0; i < mem; i++) {
		int tmp = arr[i];
		arr[i] = arr[getrand(0, mem)];
		arr[getrand(0, mem)] = tmp;
	}
}

int main()
{
	FILE *text = fopen("test.txt", "r");
	int mem = 20;
	int arr[mem];
	write_to_arr(arr, mem);
	//print_arr(arr, mem);
	mix(arr, mem);
	//printf("\n");
	//print_arr(arr, mem);
	//return 0;
	
	//char *key = malloc(sizeof(char) * mem);
	char *buffer;
	size_t len = 0;
	int count = 1;
	getline(&buffer, &len, text); 
		bstree_t *root = bstree_create(buffer, arr[0]);
	printf("success: value(%d), key - %s", arr[0], buffer);
	for (int i = 1; getline(&buffer, &len, text) != -1 ; i++) {
		//bstree_t *a = bstree_create(buffer, arr[i]);
		bstree_add(root, buffer, arr[i]);
		printf("success: value(%d), key - %s", arr[i], buffer);
		count++;
	}
	printf("%d\n", count);
	fclose(text);
	
	bstree_t *tmp = bstree_lookup(root, 6);
	printf("success search: key - %s, value - %d\n", tmp->key, tmp->value);
	
	return 0;
}
