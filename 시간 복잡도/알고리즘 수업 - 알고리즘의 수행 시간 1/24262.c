#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int MenOfPassion(int A[], int n) {
    int i = n / 2;
    return A[i];
}
int main(void)
{
    int A[250000] = { 0 }, i, n, x = 1;
    scanf("%d", &n);
    for (i = 0; i < 250000; i++)
        A[i] = i;
    while(x!=0)
    {
        x = MenOfPassion(A, n);
        n = x;
    }
    printf("1\n%d", x);
}