#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int n = 0, num = 0;
	scanf("%d", &n);
	int* B = (int*)malloc(sizeof(int) * 10001);
	memset(B, 0, 10001 * sizeof(int));

	for (int i = 0; i < n; i++) { //n개의 숫자를 입력받는다
		scanf("%d", &num);
		B[num]++;
	}


	for (int i = 1; i < 10001; i++) { 
		for (int j = 0; j < B[i]; j++)
			printf("%d\n", i);
	}

	free(B);
	return 0;
}
