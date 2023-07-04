#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[1001], b[1001], c[1001];
	int aLen = 0, bLen = 0, len=0, cLen = 0;
	int finish = 0, z = 0;

	scanf("%s %s", a, b);
	aLen = strlen(a);
	bLen = strlen(b);
	for (int i = 0; i < aLen; i++)
		a[i] -= '0';
	for (int i = 0; i < bLen; i++)
		b[i] -= '0';
	aLen -= 1;
	bLen -= 1;
	if (aLen > bLen)
		len = aLen;
	else
		len = bLen;
	cLen = len + 1;
	c[0] = -1;
	c[cLen + 1] = '\0';

	for (int i = len; i >= 0; i--) {
		if (aLen < 0) {
			aLen = 0;
			a[aLen] = 0;
		}
		if (bLen < 0) {
			bLen = 0;
			b[bLen] = 0;
		}

		if (a[aLen] + b[bLen] + z > 9) {
			int k = a[aLen--] + b[bLen--] + z;
			c[cLen--] = k % 10;
			k /= 10;
			z = k % 10;
		}
		else {
			c[cLen--] = a[aLen--] + b[bLen--] + z;
			z = 0;
		}


	}

	for (int i = 0; c[i] != '\0'; i++) {
		if(i==0&&z!=0)
			printf("%d ", c[i]);
		if(i!=0)
			printf("%d ", c[i]);
	}
}