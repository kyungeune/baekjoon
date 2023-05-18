#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int arr[10][10];
	int i, j, max = -10000, maxNumX=-1,maxNumY = -1;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > max) {
				max = arr[i][j];
				maxNumX = i + 1;
				maxNumY = j + 1;
			}

		}
	}

	printf("%d\n%d %d", max, maxNumX, maxNumY);

}