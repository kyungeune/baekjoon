#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int x, y, z, temp=0;

	scanf("%d %d %d", &x, &y, &z);


	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if (x < z) 
	{
		temp = x;
		x = z;
		z = temp;
	}
	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if (y < z)
	{
		temp = y;
		y = z;
		z = temp;
	}

	printf("%d %d %d", z, y, x);

	return 0;
}