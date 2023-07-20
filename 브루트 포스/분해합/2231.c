#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, m = 0;

	scanf("%d", &n);
	for (int i = n - 63; i < n; i++)
	{
		int sum = i, x = i;
		while (x > 0) {
			sum += x % 10;
			x /= 10;
		}
		if (n == sum) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}