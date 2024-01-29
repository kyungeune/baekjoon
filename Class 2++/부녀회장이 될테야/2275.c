#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15
#include <stdio.h>
int main(void)
{
	int t, k, n;
	int a[SIZE][SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {
			if (i == 0)
				a[i][j] = j + 1;
			else {
				for (int k = 0; k <= j; k++) {
					a[i][j] += a[i - 1][k];
				}
			}
			//printf("%d", a[i][j]);
		}
		//printf("\n");

	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &k, &n);
		printf("%d \n", a[k][n - 1]);
	}

	return 0;
}