#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int count = 0, alpha = 65, i, haha = 0;
	char s[1000001] = { 0 };
	char ch;

	fgets(s, sizeof(s), stdin);

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\n')
			break;
		if (s[i] == ' ' && haha == 1) {
			count++;
			haha = 0;
		}
		else if (s[i] == ' ' && haha == 0) {
			haha = 0;
		}
		else
			haha = 1;
	}

	if (haha == 0)
		printf("%d", count);
	else
		printf("%d", count + 1);

	return 0;
}