#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void change(int* B, int begin, int end, int mid)
{
	int first[100], second[100];
	int k = 0, z = 0;

	begin -= 1;
	end -= 1;
	mid -= 1;

	for (int i = begin; i < mid; i++)
		first[k++] = B[i];
	k = 0;
	for (int i = mid; i < end + 1; i++)
		second[k++] = B[i];

	k = begin;
	for (int i = mid; i < end + 1; i++)
		B[k++] = second[z++];
	z = 0;
	for (int i = begin; i < mid; i++)
		B[k++] = first[z++];

}

int main(void)
{
	int* B;
	int n, m, i;
	
	scanf("%d %d", &n, &m);

	B = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		B[i] = i + 1;

	for (int a = 0; a < m; a++)
	{
		int ii, j, k;
		scanf("%d %d %d", &ii, &j, &k);
		change(B, ii, j, k);
	}

	for (i = 0; i < n; i++)
		printf("%d ", B[i]);

	free(B);
	return 0;
}