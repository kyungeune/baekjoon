#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, * A, max = -1000000, maxidx = 0;

	A = (int*)malloc(sizeof(int) * 9);

	for (i = 0; i < 9; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < 9; i++) {
		if (A[i] > max) {
			max = A[i];
			maxidx = i;
		}
	}

	printf("%d %d", A[maxidx], maxidx+1);

	free(A);
	return 0;
}