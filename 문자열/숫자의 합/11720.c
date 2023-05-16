#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n=0, i, sum=0;
	char s[100];
	scanf("%d",&n);
	scanf("%s", s);

	for (i = 0; i < n; i++) {
		sum += s[i] - 48;
	}

	printf("%d", sum);

	return 0;
}