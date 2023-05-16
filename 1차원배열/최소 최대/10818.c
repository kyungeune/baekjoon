#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, n, * A, min=1000000, max=-1000000, minidx=0, maxidx=0;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < n; i++) {
		if (A[i] < min) {
			min = A[i];
			minidx = i;
		}
		if (A[i] > max) {
			max = A[i];
			maxidx = i;
		}
	}

	printf("%d %d", A[minidx], A[maxidx]);

	free(A);
	return 0;
}