#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int A[], int n)
{
	int i, j, k, tmp;
	for (int i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++) // 1 2 3 5 4 9 7 3
			if (A[i] < A[j]) // 1 2 3 (5=A[j] > 4=A[i]) 9 7 3
				break;

		tmp = A[i];
		for (k = i; k > j; k--) //i까지 오른쪽으로 다 미루기
			A[k] = A[k - 1];
		A[k] = tmp;
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
	insertionSort(A, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	free(A);
	return 0;
}