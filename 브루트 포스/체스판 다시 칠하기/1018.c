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
	for (int i = 0; i < n; i++) //2���� �����Ҵ�
		a[i] = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}


	while (i>=0)
	{
		int sum = 0; //W���� �ٵϾ��� ���� ���
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
		if (sum < min) //�̶��� �ּڰ��� min���� �۴ٸ�
			min = sum;

		sum = 0; //B���� �ٵϾ��� ���� ���
		for (int x = i - 8; x < i; x++) {
			for (int y = j - 8; y < j; y++)
			{
				if (x % 2 == 0 && y % 2 == 0) { //B�� �־�� �� �ڸ���
					if (a[x][y] != 'B') //B�� ���ٸ�
						sum++; //sum�� 1 ���϶�
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
		if (sum < min) //�̶��� �ּڰ��� min���� �۴ٸ�
			min = sum;

		if (i == n && j == m) //i�� j�� �������̸� �ݺ����� ����������
			break;
		

		if (j == m) { //j�� m���� ���ٸ�
			j = 7; //���� ���� �ٽ� ó������ �������
			i++;
		}
	}


	printf("%d", min);

	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
	return 0;
}