#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 1
        for j <- i + 1 to n
            sum <- sum + A[i] �� A[j]; # �ڵ�1
    return sum;
}

==

n*(n-1)/2
*/
long long MenOfPassion(int A[], long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n - 1; i++) //n��
        for (long long j = i + 1; j <= n; j++) //n��
            sum += 1;
    //���������� n������
    return sum;
}
int main(void)
{
    int A[1] = { 0 };
    long long n, x = 1;
    scanf("%llu", &n);
    printf("%llu\n2", (n-1)*(n)/2);
}