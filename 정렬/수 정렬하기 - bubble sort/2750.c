#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	bubbleSort(A, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	free(A);
	return 0;
}