#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	long long* l = (long long*)malloc(sizeof(long long) * 1000000);

	

	free(l);

	return 0;
}
