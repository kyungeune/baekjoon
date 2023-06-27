#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

struct Student {
    int age;
    char name[50];
};

int partition(struct Student* A, int p, int r) {
    int i, j, allSame = 1;
    struct Student t;

    i = p - 1;
    
    for (j = p; j < r; j++) {
        if (A[j].age < A[r].age) {
            i++;
            //A[i] <-> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
        if (A[j].age != A[r].age)
            allSame = 0;
    }

    if (allSame == 0)
    {
        i++;
        t = A[i];
        A[i] = A[r];
        A[r] = t;
    }

    return i;
}

void quickSort(struct Student* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n, i;
    struct Student* A;

    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }

    A = (struct Student*)malloc(sizeof(struct Student) * n);
    if (A == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &A[i].age);
        scanf("%s", &A[i].name);
    }

    quickSort(A, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d %s", A[i].age, A[i].name);
        if (i != n - 1)
            printf("\n");
    }

    free(A);
    return 0;
}