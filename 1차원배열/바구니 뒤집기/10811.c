#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, i, m, z, x, y, temp =0, length=0;
	int* A;
	scanf("%d %d", &n, &m);
	A = (int*)malloc(sizeof(int) * (n+1));
	for (i = 0; i < n + 1; i++)
		A[i] = i;

	for (z = 0; z < m; z++) {
		scanf("%d %d", &x, &y);
		do{
			temp = A[x];
			A[x] = A[y];
			A[y] = temp;
			x++;
			y--;
		} while (x < y);
	}

	for (i = 1; i <= n; i++)
		printf("%d ", A[i]);
}