#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str1 = "резьба";
	char *str2 = "резьба";
	printf("%d\n", strcmp(str1, str1));
	printf("%d\n", strcmp(str2, str2));
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strcmp(str2, str1));
}
