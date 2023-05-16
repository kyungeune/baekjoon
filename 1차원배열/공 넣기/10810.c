#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* B, i, n, count;
	scanf("%d", &n);
	scanf("%d", &count);

	B = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		B[i] = 0;
	}//BÃÊ±âÈ­

	for (i = 0; i < count; i++) {
		int first; scanf("%d",&first);
		int last; scanf("%d", &last);
		int number; scanf("%d", &number);
		for (int j = first; j <= last; j++) {
			B[j-1] = number;
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", B[i]);

	free(B);
	return 0;
}