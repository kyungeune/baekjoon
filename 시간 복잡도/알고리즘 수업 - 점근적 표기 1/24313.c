#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n //1번
        for j <- 1 to n //2번
            for k <- 1 to n //3번
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
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