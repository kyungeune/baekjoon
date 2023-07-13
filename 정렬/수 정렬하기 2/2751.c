#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(long long* A, long long p, long long q, long long r, long long* temp) {
    long long i, j, t;

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

void mergeSort(long long* A, long long p, long long r, long long* temp) {
    if (p < r) {
        long long q = (p + r) / 2;
        mergeSort(A, p, q, temp);
        mergeSort(A, q + 1, r, temp);
        merge(A, p, q, r, temp);
    }
}

int main() {
    long long* A;
    long long* temp;
    long long i, n;

    scanf("%llu", &n);
    if (n <= 0) {
        return 0;
    }

    A = (long long*)malloc(sizeof(long long) * n);
    temp = (long long*)malloc(sizeof(long long) * n);
    if (A == NULL || temp == NULL) {
        return 0;
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        scanf("%llu", &A[i]);
    }


    mergeSort(A, 0, n - 1, temp);

    for (i = 0; i < n; i++)
        printf("%lld\n", A[i]);

    free(temp);
    free(A);
    return 0;
}