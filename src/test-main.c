#include <stdio.h>

TODO: !!!

void mix(char *str, const int n)
{
	int tmp = n - 1;
	for (int i = 0; tmp > 0; i++) {
		char *tmp_str = str[];
	}
}

int main(void)
{
	FILE *text = fopen("text.txt", "r");
	char *buf;
	char *str[10];
	int len = 0;
	for (int i = 0; getline(&buf, &len, text) != -1; i++) {
		str[i] = malloc(sizeof(buf));
		strcpy(str[i], buf);
	}
	mix(str, 10);
}