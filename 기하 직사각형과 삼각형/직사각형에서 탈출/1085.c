#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	long long x, y, w, h, min, k = 0;	scanf("%llu %llu %llu %llu", &x, &y, &w, &h);

	min = w;

	for (int i = 0; i < 4; i++) {

		if (i == 0)

			k = w - x;

		if (i == 1)

			k = x;

		if (i == 2)

			k = h - y;

		if (i == 3)

			k = y;

		if (k < min) {

			min = k;

		}

	}

	printf("%llu", min);

}