#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int n, m, sum = 0, min = -1;

	scanf("%d %d", &m, &n);



	for (int i = m; i <= n; i++) {

		if (i == 1)

			i++;

		if (m == 1 && m == n) {

			min = -1;

			break;

		}

		int sosu = 1;

		for (int j = 2; j <= i / 2; j++) {

			if (i % j == 0) {

				sosu = 0;

				break;

			}

		}

		if (sosu == 1) {

			if (min == -1)

				min = i;

			sum += i;

		}

	}



	if (min == -1)

		printf("-1");

	else

		printf("%d\n%d", sum, min);

}