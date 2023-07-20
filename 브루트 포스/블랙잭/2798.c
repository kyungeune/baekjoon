#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int realSum = -1;
void pick(int* A, int* picked, int n, int m, int toPick)
{
	int sum = 0;
	int lastIndex = 3 - toPick - 1;

	for (int i = 0; i <= lastIndex; i++) {
		sum += A[picked[i]];
		//printf("%d ", A[picked[i]]);
		if (sum > m)
			return;
	}
	//printf("\n");

	if (toPick == 0) {
		sum = 0;

		for (int i = 0; i < 3; i++) {
			sum += A[picked[i]];
			if (sum > m)
				return;
		}

		if (sum > realSum)
			realSum = sum;
	}

	int smallest = 0;

	if (toPick == 3)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	for (int i = smallest; i < n; i++) {
		if (realSum == m)
			break;
		int j, flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == i)
				flag = 1;
		if (flag == 1)	continue;
		picked[lastIndex + 1] = i;
		pick(A, picked, n, m, toPick - 1);
	}
}

int main(void)
{
	int n, m;
	int* A;
	int picked[10000];

	scanf("%d %d", &n, &m);

	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	pick(A, picked, n, m, 3);

	printf("%d", realSum);

	free(A);
	return 0;
}