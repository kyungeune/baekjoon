#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//이진탐색과 정렬 활용
int main(void)
{
	int n;
	scanf("%d", &n);
	int* A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int m;
	scanf("%d", &m);
	int* B = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < m; i++) {
		int is = 0;
		for (int j = 0; j < n; j++) {
			if (B[i] == A[j]) {
				is = 1;
				break;
			}
		}
		if(is==0)
			printf("0 ");
		else
			printf("1 ");
	}

	free(A);
	free(B);
	return 0;
}