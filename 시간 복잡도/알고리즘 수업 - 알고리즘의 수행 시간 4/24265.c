#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int MenOfPassion(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            sum += 1;
    return sum;
}
int main(void)
{
    int A[500000] = { 0 }, i, n, x = 1;
    scanf("%d", &n);
    printf("%d\n2", MenOfPassion(A,n));
}