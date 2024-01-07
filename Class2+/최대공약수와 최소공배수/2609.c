#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int n, m, yak = 0, be = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m * n; i++) {
		if (m % i == 0 && n % i == 0)
			yak = i;
	}
	for (int i = (n>m)?n:m; i <= m * n; i++) {
		if (i % n == 0 && i % m == 0) {
			be = i;
			break;
		}
	}
	
	printf("%d\n%d", yak, be);

	return 0;
}