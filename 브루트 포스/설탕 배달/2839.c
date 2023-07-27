#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, flag = 0;
	scanf("%d", &n);
	for (int i = 0;i<=n/3; i++)
	{
		for (int j = 0; j <= n / 3; j++)
			if (i * 3 + j * 5 == n) {
				printf("%d", i + j);
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
	}

	if (flag == 0)
		printf("-1");
}