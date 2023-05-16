#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char s[101];
	int i, count=0, len;

	scanf("%s", s);
	len = strlen(s);

	for (i = 0; i < len; i++) {
		count++;
		if (s[i] == '=') {
			if (s[i - 1] == 'c' || s[i - 1] == 's')
				count--;
			if (s[i - 1] == 'z') {
				count--;
				if (s[i - 2] == 'd')
					count--;
			}
		}
		else if (s[i] == '-') {
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
				count--;
		}
		else if (s[i] == 'j') {
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				count--;
		}

	}

	printf("%d", count);
}