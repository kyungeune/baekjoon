#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, num, *A, i, sum=0;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &num);

	for (i = 0; i < n; i++) {
		if (num == A[i])
			sum++;
	}

	printf("%d", sum);

	free(A);

	return 0;
}