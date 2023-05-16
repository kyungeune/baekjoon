#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, max = 0;
	double *A, sum = 0;

	scanf("%d", &n);
	A = (double*)malloc(sizeof(double) * n);

	for (int i = 0; i < n; i++) { //점수들의 최댓값 구하기
		scanf("%lf", &A[i]);
		if (A[i] > max)
			max = A[i];
	}

	for (int i = 0; i < n; i++) { //점수 조작 중
		A[i] = (double)(A[i] / max) * 100;
		sum += A[i];
	}
	
	printf("%f", sum / n);

	free(A);
	return 0;
}