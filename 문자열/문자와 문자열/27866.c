#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char s[1000];
	int n, length, i;

	scanf("%s %d", s, &n);

	for (i = 0; s[i] != '\0'; i++)
		if (n - 1 == i)
			printf("%c", s[i]);
}