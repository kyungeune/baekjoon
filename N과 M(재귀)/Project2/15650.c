/*
	풀이법 : 조합
	링크 : https://www.acmicpc.net/problem/15650
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* picked, int m, int toPick)
{
	int i;
	int lastIndex;
	int smallest;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", picked[i] + 1);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		int j = 0; int flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == i) flag = 1;
		if (flag == 1)continue;
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);
	}
}

int main(void)
{
	int n, m;
	int* picked;

	scanf("%d %d", &n, &m);

	picked = (int*)malloc(sizeof(int) * m);

	pick(n, picked, m, m);

	return 0;
}