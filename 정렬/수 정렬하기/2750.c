#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long partition(long long* A, long long p, long long r) {
    long long i, j;
    long long t;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            //A[i] <-> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;
    return i;
}

void quickSort(long long* A, long long p, long long r) {
    if (p < r) {
        long long q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    long long* A;
    long long i, n;

    scanf("%llu", &n);
    if (n <= 0) {
        return 0;
    }

    A = (long long*)malloc(sizeof(long long) * n);
    if (A == NULL)
        return 0;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        scanf("%llu", &A[i]);

    quickSort(A, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%lld\n", A[i]);

    free(A);
    return 0;
}