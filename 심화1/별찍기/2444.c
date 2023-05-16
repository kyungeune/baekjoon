#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, x, i, j, front = 1;
	
	scanf("%d", &n);

	x = n - 1;

	for (i = 0; i < n * 2 - 1; i++)
	{
		for (j = 0; j < x; j++)
			printf(" ");
		for (j = 0; j < n * 2 - 1 - x * 2; j++)
			printf("*");
		if (front == 0 && x == n - 1)
			break;
		printf("\n");

		if (x == 0)
			front = 0;
		if (front == 1)
			x--;
		else
			x++;
	}
}