#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long merge(long long* B, long long* A, long long p, long long q, long long r, long long* temp, long long n) {
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

    for (i = p; i <= r; i++) {
        A[i] = temp[i];
        for (j = 0; j < n; j++)
        {
            if (A[j] != B[j])
                return 0;
        }
    }
    return 1;
}

long long mergeSort(long long* B, long long* A, long long p, long long r, long long* temp, long long n) {
    if (p < r) {
        long long q = (p + r) / 2;
        long long a = mergeSort(B, A, p, q, temp, n);
        printf("a %lld ", a);
        /*if (a == 1)
            return 1;*/
        long long b = mergeSort(B, A, q + 1, r, temp, n);
        printf("b %lld ", b);
        /*if (b == 1)
            return 1;*/
        long long c = merge(B, A, p, q, r, temp, n);
        return c;
    }
}

int main() {
    long long* A;
    long long* temp;
    long long* B;
    long long i, n;

    scanf("%llu", &n);
    if (n <= 0) {
        return 0;
    }

    A = (long long*)malloc(sizeof(long long) * n);
    B = (long long*)malloc(sizeof(long long) * n);
    temp = (long long*)malloc(sizeof(long long) * n);
    if (A == NULL || temp == NULL) {
        return 0;
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        scanf("%llu", &A[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%llu", &B[i]);
    }

    printf("%lld", mergeSort(B, A, 0, n - 1, temp, n));
    
    free(temp);
    free(A);
    free(B);
    return 0;
}