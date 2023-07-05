#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int n, sosu = 0;

	scanf("%d", &n);



	while (n != 1 && sosu != 1)

	{

		sosu = 1;

		for (int j = 2; j <= n / 2; j++) { //소수판별

			if (n % j == 0) {

				sosu = 0;

				printf("%d\n", j);

				n /= j;

				break;

			}

		}





	}

	if (n != 1)

		printf("%d", n);

}