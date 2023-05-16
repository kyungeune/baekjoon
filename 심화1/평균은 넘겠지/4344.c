#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	double sum = 0;
	int i, j, n, m;
	int* A;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		sum = 0;
		scanf("%d", &m);
		A = (int*)malloc(sizeof(int) * m);

		for (j = 0; j < m; j++) {
			A[j] = 0;
			scanf("%d", &A[j]);
			sum += A[j];
		}
		double avg = (double)sum / m;
		sum = 0;
		for (j = 0; j < m; j++) {
			if (A[j] > avg)
				sum += 1;
		}

		printf("%.3f%%\n", (double)(sum*100 / m));
		free(A);
	}

	return 0;
}