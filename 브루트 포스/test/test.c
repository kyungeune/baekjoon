#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int n, int data[]) {
    if (n <= 0)
        return 0;
    else
        return sum(n - 1, data) + data[n - 1];
}
int main(void) 
{
    int n;
    scanf("%d", &n);
    printf("%d��° �Ǻ���ġ ���� %d�Դϴ�.\n", n, fibonacci(n));
    return 0;
}