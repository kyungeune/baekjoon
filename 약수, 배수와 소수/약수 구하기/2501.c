#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int x, n, count = 1, i;

	scanf("%d%d", &x, &n);



	for (i = 2; i <= x / 2; i++) {

		if (n == 1) {

			printf("1");

			break;

		}

		if (x % i == 0) {

			count++;

		}

		if (count == n) {

			printf("%d", i);

			break;

		}

		if (count > n) {

			printf("0");

			break;

		}

		if (count + 1 != n && i == x / 2)

			printf("0");

	}

	if (count + 1 == n)

		printf("%d", x);

	return 0;

}