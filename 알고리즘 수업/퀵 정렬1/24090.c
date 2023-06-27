#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <time.h>



long long key, count = 0;

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

            count++;

            if (count == key) {
                if (A[i] < A[j]) {
                    printf("%lld %lld", A[i], A[j]);
                }
                else {
                    printf("%lld %lld", A[j], A[i]);
                }

            }

        }

    }



    i++;

    t = A[i];

    A[i] = A[r];

    A[r] = t;

    count++;

    if (count == key) {
        if (A[i] < A[r]) {
            printf("%lld %lld", A[i], A[r]);
        }
        else {
            printf("%lld %lld", A[r], A[i]);
        }
        return -1;

    }

    return i;

}



void quickSort(long long* A, long long p, long long r) {

    if (p < r) {

        long long q = partition(A, p, r);
        if (count <= key) {
            quickSort(A, p, q - 1);
        }

        if (count <= key) {
            quickSort(A, q + 1, r);
        }



    }

}



int main(void) {

    long long* A;

    long long i, n;



    scanf("%llu %llu", &n, &key);

    if (n <= 0) {

        return 0;

    }



    A = (long long*)malloc(sizeof(long long) * n);

    if (A == NULL)

        return 0;



    srand(time(NULL));

    for (i = 0; i < n; i++)

        scanf("%lld", &A[i]);

    quickSort(A, 0, n - 1);

    if (count < key) {

        printf("-1");

    }

    free(A);

    return 0;

}