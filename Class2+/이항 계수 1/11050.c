#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int x = 0, y = 0, ans = 0;
	scanf("%d %d", &x, &y);

	if (y >= 0 && y <= x) {
		int z = x - y;
		ans = 1;
		for (int i = 0; i < y; i++) {
			ans *= x;
			x--;
		}
		while (y >= 1) {
			ans /= y;
			y--;
		}
	}

	printf("%d", ans);
}