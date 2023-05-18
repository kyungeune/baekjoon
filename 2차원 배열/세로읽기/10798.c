#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int i, j;
	int arr[15][15];
	char s[16];

	for (i = 0; i < 5; i++)
	{
		scanf("%s", s);
		for (j = 0; j < strlen(s); j++)
		{
			arr[i][j] = s[j];
		}
		for (j = strlen(s); j < 15; j++)
			arr[i][j] = -1;
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if(arr[j][i]!=-1)
				printf("%c", arr[j][i]);
		}
	}
}