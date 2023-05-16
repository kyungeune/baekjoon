#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, num, * A, i;

	scanf("%d", &n);
	scanf("%d", &num);

	A = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < n; i++) {
		if (num > A[i])
			printf("%d ",A[i]);
	}

	free(A);

	return 0;
}