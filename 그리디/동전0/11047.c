#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int picked[], int m, int toPick, int money[]) {
    int i;
    int lastIndex;
    int smallest;

    if (toPick == 0) {
        for (i = 0; i < m; i++) {
            printf("%d ", picked[i]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = 0; i < n; i++) {
        int j = 0; int flag = 0;
        picked[lastIndex + 1] = i;
        pick(n, picked, m, toPick - 1, money);
    }

}

int main(void)
{
    int m, n;
    int* picked;
    int* money;
    scanf("%d %d", &m, &n);

    picked = (int*)malloc(sizeof(int) * m);
    money = (int*)malloc(sizeof(int) *m);

    for (int i = 0; i < m; i++)
        scanf("%d", &money[i]);

    pick(n, picked, m, m, money);

    free(picked);
    return 0;
}