#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//완성된 버전이 절대 아님
void MAX_HEAPIFY(int A[], int i, int n)
{
	int k;
	if (2 * i > n)
		return;
	if (2 * i + 1 > n)//자식이 하나면
		k = 2 * i;
	else if (A[2 * i] > A[2 * i + 1])
		k = 2 * i;
	else
		k = 2 * i + 1;

	if (A[i] >= A[k])
		return;

	int temp = A[i];
	A[i] = A[k];
	A[k] = temp;

	MAX_HEAPIFY(A, k, n);
}

void BUILD_MAX_HEAP(int A[], int n) //시간복잡도 : O(n)
{
	int heap_size = n;
	for (int i = n / 2; i >= 1; i--) //처음으로 leaf 노드가 아닌 노드 == n의 부모노드 == A[N/2]
		MAX_HEAPIFY(A, i, n);
}

void HEAP_SORT(int A[], int n)
{
	BUILD_MAX_HEAP(A, n);
	for (int i = n; i >= 2; i--) {
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		MAX_HEAPIFY(A, 1, n);
	}
}

void MAX_HEAP_INSERT(int A[], int key, int n)
{
	int heap_size = n;
	heap_size += 1;
	A[heap_size] = key;
	int i = heap_size;
	while (i > 1 && A[i/2] < A[i]) {
		int temp = A[i / 2];
		A[i / 2] = A[i];
		A[i] = temp;
		i = i / 2;
	}
}

void HEAP_EXTRACT_MAX(int A[], int n)
{
	if (n < 1)
		return;
	int max = A[1];
	int heapsize = n;
	A[1] = A[heapsize];
	heapsize--;
	MAX_HEAPIFY(A, 1, heapsize);
	return max;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int* A = (int*)malloc(sizeof(int) * (n + 1));
	A[0] = 0;
	for (int i = 1; i < n + 1; i++)
		scanf("%d", &A[i]);
	HEAP_SORT(A, n);
	for (int i = 1; i < n + 1; i++)
		printf("%d ", A[i]);
	free(A);
	return 0;
}