#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 200001

typedef struct {
	int x, y;
} Point;

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		arr[i] = (int*)malloc(sizeof(int) * SIZE);
		memset(arr[i], -1, SIZE * sizeof(int));
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			scanf("%d %d", &x, &y);

		}
	}

	arr[0][3] = 1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] != -1) {
				printf("%d", arr[i][j]);
			}

		}
	}


	for (int i = 0; i < SIZE; i++)
		free(arr[i]);
	free(arr);
	return 0;
}
