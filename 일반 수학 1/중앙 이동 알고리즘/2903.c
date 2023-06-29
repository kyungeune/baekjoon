#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{

	int num, k = 0, numm = 1;	scanf("%d", &num);

	for (int i = 1; i < num; i++) {

		numm *= 2;

	}

	k = numm * 2 + 1;

	printf("%d", k * k);

}