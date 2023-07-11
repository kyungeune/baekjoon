#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n1", n);
}
/*
long long count = 0;
long long MenOfPassion(long long A[], long long n) {
    long long sum = 0;
    count++;
    for (long long i = 0; i < n; i++)
        sum += A[i];
    return sum;
}
long long main(void)
{
    long long A[500000]={0}, n = 0, x = 0;
    scanf("%llu", &n);
    for (long long i = 0; i < 500000; i++)
        A[i] = 1;
    x = MenOfPassion(A, n);
    printf("%llu\n%llu", x, count);
}*/