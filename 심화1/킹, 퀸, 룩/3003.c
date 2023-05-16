#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int original[6]={1,1,2,2,2,8};
	int n[6];

	for (int i = 0; i < 6; i++)
		scanf("%d", &n[i]);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", original[i] - n[i]);
	}
}