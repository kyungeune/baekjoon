#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r, int temp[])
{
	int i = p, j = q + 1, k = p;

	while (i <= q && j <= r) {
		if (A[i] < A[j]) //�� ���� ���� temp�� ���ʴ�� ��´�.
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	if (i > q) //���� ������ temp�� ���� ��´�
		for (; j <= r; j++, k++)
			temp[k] = A[j];
	else
		for (; i <= q; i++, k++)
			temp[k] = A[i];

	for (int z = p; z <= r; z++) //�ٽ� A�迭�� �Ű��ش�
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
	int n;
	scanf("%d", &n);
	if (n <= 0)
		return 0;
	int* A = (int*)malloc(sizeof(int) * n);
	int* temp = (int*)malloc(sizeof(int) * n); //A���� ���� �ӽ� ����
	if (A == NULL)
		return 0;
	if (temp == NULL)
		return 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	mergeSort(A, 0, n - 1, temp); //n-1�� �ִ� ���� : x<=y �������� merge �� ���̱� ������
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	free(A);
	free(temp);
	return 0;
}