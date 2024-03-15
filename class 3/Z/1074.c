#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, r, c, x = 1;

	scanf("%d %d %d", &n, &r, &c);

	while (x * x <= n) {
		printf("%d\n", x * x);
		x += x;
	}
	int y = x / 2;
	// printf("x * x : %d, x : %d\n", x * x, x);
	// x * x : 64, x : 8, y : 4



	return 0;
}