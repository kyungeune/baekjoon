#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int p, int q, int r, int* temp) {
    int i, j, t;

    i = p;
    j = q + 1;
    t = p;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            temp[t] = A[i];
            t++; i++;
        }
        else {
            temp[t] = A[j];
            t++; j++;
        }
    }

    if (j > r) {
        for (; i <= q; i++, t++)
            temp[t] = A[i];
    }
    else {
        for (; j <= r; j++, t++)
            temp[t] = A[j];
    }

    for (i = p; i <= r; i++)
        A[i] = temp[i];
}

void mergeSort(int* A, int p, int r, int* temp) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q, temp);
        mergeSort(A, q + 1, r, temp);
        merge(A, p, q, r, temp);
    }
}

int binary(int )

int main(void)
{
	int n, checkN;
	scanf("%d", &n);
	int* A = (int*)malloc(sizeof(int) * n);
    int* temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &checkN);
	int* Check = (int*)malloc(sizeof(int) * checkN);
    //병합정렬
    mergeSort(A, 0, n - 1, temp);
     
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
     
     
	//이진탐색
    int answer = binary(A, n, Check, checkN);
    printf("%d", answer);

	free(A);
	free(Check);
	return 0;
}