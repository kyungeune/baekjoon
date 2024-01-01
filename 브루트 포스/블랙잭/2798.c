#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = 0;
void pick(int num[], int n, int picked[], int m, int toPick, int limit) {
    int i;
    int lastIndex;
    int smallest;

    int sum = 0;
    for (i = 0; i < m - toPick - 1; i++) {
        sum += num[picked[i]];
        if (sum > limit)
            return;
    }

    if (toPick == 0) {
        sum = 0;
        for (i = 0; i < m; i++) {
            sum += num[picked[i]];
            if (sum > limit)
                return;
        }
        
        if (sum > max && sum <= limit)
            max = sum;

        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = 0; i < n; i++) {
        int j = 0; int flag = 0;
        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i) flag = 1;
        if (flag == 1) continue;
        picked[lastIndex + 1] = i;
        pick(num, n, picked, m, toPick - 1, limit);
    }

}

int main(void)
{
    int n, limit;
    int* picked;
    int* num;

    scanf("%d %d", &n, &limit);

    picked = (int*)malloc(sizeof(int) * 3);
    num = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    pick(num, n, picked, 3, 3, limit);

    printf("%d", max);

    free(picked);
    return 0;
}