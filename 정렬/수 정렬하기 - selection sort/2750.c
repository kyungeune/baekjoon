#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void selectionSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--) 
	{
		int max=A[i], maxNum = i;
		for (int j = 0; j < i; j++)
			if (A[j] > max) 
			{
				max = A[j];
				maxNum = j;
			}
		int temp = A[maxNum];
		A[maxNum] = A[i];
		A[i] = temp;
	}
}

int main(void)
{
	int* A;
	int n;
	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	selectionSort(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	free(A);
	return 0;
}