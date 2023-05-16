#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char s[100];
	int length, n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (length = 0; s[length] != '\0'; length++);
		printf("%c%c\n", s[0], s[length - 1]);
	}
}