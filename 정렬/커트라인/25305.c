#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void insertionSort(int A[], int n)

{

	int i, j, k;	for (i = 1; i < n; i++) {

		for (j = 0; j < i; j++) {

			if (A[i] > A[j])

				break;

		}



		int temp = A[i];

		for (k = i; k > j; k--)

			A[k] = A[k - 1];

		A[j] = temp;

	}

}

int main(void)

{

	int* A;

	int n, pri;

	scanf("%d %d", &n, &pri);

	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &A[i]);

	}



	insertionSort(A, n);



	printf("%d", A[pri - 1]);



	free(A);

	return 0;

}