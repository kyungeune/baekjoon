#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char s[100];
	int length;
	scanf("%s", s);
	for (length = 0; s[length] != '\0'; length++);
	printf("%d", length);
}