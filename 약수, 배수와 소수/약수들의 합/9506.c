#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int n = 0, i, aNum = 0, sum = 1;	int a[1000] = { 0 };

	scanf("%d", &n);



	while (n != -1) {

		for (i = 2; i <= n / 2; i++) { //약수 넣기

			if (n % i == 0) {

				a[aNum++] = i;

				sum += i;

			}

		}



		if (sum == n) {

			printf("%d = 1", n);

			for (i = 0; i < aNum; i++) {

				printf(" + %d", a[i]);

			}

			printf("\n");

		}
		else {

			printf("%d is NOT perfect.\n", n);

		}



		scanf("%d", &n);

		aNum = 0;

		sum = 1;

	}

}