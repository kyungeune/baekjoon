#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int A[101][101]={0}, n, i, j, z, x, y, sum=0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		for (j = y; j < y + 10; j++) {
			for (z = x; z < x + 10; z++) {
				A[j][z]++;
			}
		}
	}

	for (j = 1; j <= 100; j++) {
		for (z = 1; z <= 100; z++) {
			if (A[j][z] != 0)
				sum+=1;
		}
	}

	printf("%d", sum);
}