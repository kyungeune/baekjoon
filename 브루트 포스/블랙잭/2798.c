#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int p, int q, int r, int temp[])
{
	int i = p, j = q + 1, k = p;

	while (i <= q && j <= r) {
		if (A[i] < A[j]) //더 작은 값을 temp에 차례대로 담는다.
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	if (i > q) //남은 값들을 temp에 마저 담는다
		for (; j <= r; j++, k++)
			temp[k] = A[j];
	else
		for (; i <= q; i++, k++)
			temp[k] = A[i];

	for (int z = p; z <= r; z++) //다시 A배열로 옮겨준다
		A[z] = temp[z];
}

void mergeSort(int A[], int p, int r, int temp[])
{
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q, temp);
		mergeSort(A, q + 1, r, temp);
		merge(A, p, q, r, temp);
	}
}
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* A = (int*)malloc(sizeof(int) * n);
	int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	mergeSort(A, 0, n-1, temp);

	for (int i = n-1; i >= 2; i--) {
		int sum = 0;
		for (int j = 0; j < 3; j++)
			sum += A[i - j];
		if (sum <= m) {
			printf("%d", sum);
			break;
		}
	}

	free(A);
	free(temp);
	return 0;
}