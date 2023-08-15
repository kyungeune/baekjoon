#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int n = 0, num, a = 0, b = 0, max=0, maxIdx=0;
	scanf("%d", &num);
	int k = num;
	int* A = (int*)malloc(sizeof(int) * 10);
	int* B = (int*)malloc(sizeof(int) * 10);
	while (k > 0)
	{
		A[a++] = k % 10; //배열에 담기
		k /= 10;
		n++;
	}
	for (int i = 0; i < n; i++)
		B[i] = A[n - i - 1];

	//B 배열에 담음
	for (int i = 0; i < n; i++)
	{
		max = B[i];
		maxIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (B[j] > max)
			{
				max = B[j];
				maxIdx = j;
			}
		}

		int tmp = B[i];
		B[i] = B[maxIdx];
		B[maxIdx] = tmp;
	}
	
	for (int i = 0; i < n; i++)
		printf("%d", B[i]);
	

	free(A);
	free(B);
	return 0;
}