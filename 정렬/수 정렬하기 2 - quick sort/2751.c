#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int p, int r)
{
	int i = p - 1, j, tmp;

	for (j = p; j < r; j++)
	{
		if (A[j] < A[r]) { //새로 비교하는 값이 pivot보다 작으면
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	i++;
	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;
	return i;
}

void quickSort(int A[], int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n <= 0)
		return 0;
	int* A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	quickSort(A, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	free(A);
	return 0;
}