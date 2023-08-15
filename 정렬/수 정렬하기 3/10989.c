#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//counting정렬로 푸세요^
int main(void)
{
	int n = 0, min = 0, minIdx = 0, i, j, z;
	scanf("%d", &n);
	int* B = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		if (i == 0)
			B[i] = num;

		for (j = 0; j < i; j++)
		{
			if (num < B[j])
			{
				int tmp = B[j];
				B[j] = num;
				for (z = i; z > j + 1; z--) //하나씩 뒤로 미루기
				{
					B[z] = B[z - 1];
				}
				B[z] = tmp;
				break;
			}
		}
		if (j == i)
			B[i] = num;

	}


	for (int i = 0; i < n; i++)
		printf("%d\n", B[i]);

	free(B);
	return 0;
}
