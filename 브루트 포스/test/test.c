#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int n, int data[]) {
    if (n <= 0)
        return 0;
    else
        return sum(n - 1, data) + data[n - 1];
}
int search(int data[], int begin, int end, int target) { //binary search와는 다름
    if (begin > end)
        return -1;
    else {
        int middle = (begin + end) / 2;
        if (data[middle] == target)
            return middle;
        int index = search(data, begin, middle - 1, target); //앞쪽 검사
        if (index != -1) //찾았다! 
            return index;
        else
            return search(data, middle + 1, end, target); //뒤쪽 검사
    }
}
int main(void) 
{
    int n;
    scanf("%d", &n);
    printf("%d번째 피보나치 수는 %d입니다.\n", n, fibonacci(n));
    return 0;
}