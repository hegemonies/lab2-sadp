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
	FILE *text = fopen("war_and_peace.txt", "r");
	//int mem = 20;
	//int arr[mem];
	
	size_t len = 0;
	//int count = 1;
	//write_to_arr(arr, mem);
	//print_arr(arr, mem);
	//mix(arr, mem);
	//printf("\n");
	//print_arr(arr, mem);
	//return 0;
	char *buffer = NULL;
	char *tmp_buffer[50000];
	for (int i = 0; getline(&buffer, &len, text) != -1; i++) {
		tmp_buffer[i] = malloc(sizeof(buffer));
		strcpy(tmp_buffer[i], buffer);
	}
	for (int i = 0; i < 50000; i++) {
		printf("%s", tmp_buffer[i]);
	}
	free(buffer);
	fclose(text);
	/*
	//char *key = malloc(sizeof(char) * mem);
	//getline(&buffer, &len, text); 
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
	
	bstree_t *node_1 = bstree_add(root,)
	bstree_t *tmp = bstree_lookup(root, "absolument");
	printf("success search: key - %s, value - %d\n", tmp->key, tmp->value);
	*/
	return 0;
}