#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void insertionSort(int A[], int n)

{

	int i, j, k;	for (i = 1; i < n; i++) {

		for (j = 0; j < i; j++) {

			if (A[i] < A[j])

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

	int avg = 0, mid = 0;

	A = (int*)malloc(sizeof(int) * 5);

	for (int i = 0; i < 5; i++) {

		scanf("%d", &A[i]);

		avg += A[i];

	}

	avg /= 5;



	insertionSort(A, 5);



	printf("%d %d", avg, A[2]);



	free(A);

	return 0;

}