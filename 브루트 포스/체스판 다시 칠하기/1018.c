#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, m, i = 8, j = 7, min = 100;
	int** a;
	char s[50];
	scanf("%d %d", &n, &m);
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) //2차원 동적할당
		a[i] = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}


	while (i>=0)
	{
		int sum = 0; //W먼저 바둑알을 놓는 경우
		j++;
		for (int x = i - 8; x < i; x++) {
			for (int y = j - 8; y < j; y++)
			{
				if (x % 2 == 0 && y % 2 == 0) {
					if (a[x][y] != 'W')
						sum++;
				}
				else if (x % 2 == 0 && y % 2 != 0) {
					if (a[x][y] != 'B')
						sum++;
				}
				else if (x % 2 != 0 && y % 2 == 0) {
					if (a[x][y] != 'B')
						sum++;
				}
				else if (x % 2 != 0 && y % 2 != 0) {
					if (a[x][y] != 'W')
						sum++;
				}
			}
		}
		if (sum < min) //이때의 최솟값이 min보다 작다면
			min = sum;

		sum = 0; //B먼저 바둑알을 놓는 경우
		for (int x = i - 8; x < i; x++) {
			for (int y = j - 8; y < j; y++)
			{
				if (x % 2 == 0 && y % 2 == 0) { //B가 있어야 할 자리에
					if (a[x][y] != 'B') //B가 없다면
						sum++; //sum을 1 더하라
				}
				else if (x % 2 == 0 && y % 2 != 0) {
					if (a[x][y] != 'W')
						sum++;
				}
				else if (x % 2 != 0 && y % 2 == 0) {
					if (a[x][y] != 'W')
						sum++;
				}
				else if (x % 2 != 0 && y % 2 != 0) {
					if (a[x][y] != 'B')
						sum++;
				}
			}
		}
		if (sum < min) //이때의 최솟값이 min보다 작다면
			min = sum;

		if (i == n && j == m) //i와 j가 마지막이면 반복문을 빠져나가라
			break;
		

		if (j == m) { //j가 m까지 갔다면
			j = 7; //밑의 줄을 다시 처음부터 계산하자
			i++;
		}
	}


	printf("%d", min);

	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
	return 0;
}