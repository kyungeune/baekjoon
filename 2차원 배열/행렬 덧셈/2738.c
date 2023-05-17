#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, m, i ,j;
	scanf("%d %d", &n, &m);
	int a[100][100];
	int b[100][100];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
			b[i][j] += a[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}