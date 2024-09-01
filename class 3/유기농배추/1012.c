#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reset(int** s, int x, int y, int a, int b)
{
	if (x <= 0 || x > a || y <= 0 || y > b)
		return 0;

	s[x][y] = 0;

	return reset(s, x - 1, y, a, b) +
		reset(s, x + 1, y, a, b) +
		reset(s, x, y - 1, a, b) +
		reset(s, x, y + 1, a, b);
}
void defaul(int** s)
{
	for (int i = 0; i < 50; i++) {
		s[i] = (int*)malloc(sizeof(int) * 50); // 배열 할당

		for (int j = 0; j < 50; j++) // 초기화
			s[i][j] = 0;
	}
}
int main(void)
{
	int n = 0, m = 0, a = 0, b = 0;

	int** save = (int**)malloc(sizeof(int*) * 50);

	defaul(save);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) // m개의 케이스
	{
		scanf("%d %d %d", &a, &b, &n);

		int x = 0, y = 0, sum = 0;

		for (int j = 0; j < n; j++) {
			scanf("%d %d", &x, &y);
			save[x][y] = 1;
		}

		for (int k = 0; k < a; k++) {
			for (int l = 0; l < b; l++) {
				if (save[k][l] == 1) {
					sum++;
					int imsi = reset(save, k, l, a, b, 1);
				}
			}
		}

		printf("%d\n", sum);

		for (int k = 0; k < a; k++) { // 다시 초기화
			for (int l = 0; l < b; l++) {
				save[k][l] = 0;
			}
		}
	}
}