#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[101];
	int check = 1;

	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == s[strlen(s) - 1 - i])
			continue;
		else
		{
			check = 0;
			break;
		}
	}

	printf("%d", check);
}