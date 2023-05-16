#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, i, k, j, z;
	char s[21];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %s", &k, s);
		for (z = 0; s[z] != '\0'; z++) {
			for (j = 0; j < k; j++) {
				printf("%c", s[z]);
			}
		}
		printf("\n");
	}
}