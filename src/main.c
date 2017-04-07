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
		arr[i] = getrand(0, 500);
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
	int mem = 51179;
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
	for (int i = 0; getline(&buffer, &len, text) != -1 ; i++) {
		//fscanf(text, "%s", buffer);
		//char *key = malloc(sizeof(char) * (strlen(buffer) + 1));
		//strncpy(key, buffer, strlen(buffer) + 1);
		bstree_t *a = bstree_create(buffer, arr[i]);
		bstree_add(a, buffer, arr[i]);
	}
	fclose(text);
	return 0;
}
