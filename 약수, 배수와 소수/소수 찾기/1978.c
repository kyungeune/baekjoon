#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int n, count = 0, x = 0;

	scanf("%d", &n);



	for (int i = 0; i < n; i++) {

		int sosu = 1;

		scanf("%d", &x);

		for (int j = 2; j <= x / 2; j++) {

			if (x % j == 0) {

				sosu = 0;

				break;

			}

		}

		if (sosu == 1) {

			count++;

		}

		if (x == 1) {

			count--;

		}

	}



	printf("%d", count);

}