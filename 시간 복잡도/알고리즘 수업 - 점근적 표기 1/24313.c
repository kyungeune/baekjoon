#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n //1��
        for j <- 1 to n //2��
            for k <- 1 to n //3��
                sum <- sum + A[i] �� A[j] �� A[k]; # �ڵ�1
    return sum;
}
*/
int main(void)
{
    long long n;
    scanf("%llu", &n);
    if (n == 1)
        printf("1\n3");
    else
        printf("%llu\n3", n * n * n);
}