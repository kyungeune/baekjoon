#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int x, y, xn=0, yn=0;

	scanf("%d %d", &x, &y);

	for (int i = 0; i < 3; i++) {
		xn += x % 10;
		yn += y % 10;
		xn *= 10;
		yn *= 10;
		x /= 10;
		y /= 10;
	}
	xn /= 10;
	yn /= 10;

	if (xn > yn)
		printf("%d", xn);
	else
		printf("%d", yn);
}