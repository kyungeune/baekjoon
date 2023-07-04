#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int a, b, check = 0;	

	scanf("%d", &a);

	scanf("%d", &b);



	while (a != 0 && b != 0)

	{

		if (a == b) {

			printf("neither\n");

			check = 1;

		}



		if (b == 1) {

			printf("multiple\n");

			check = 1;

		}



		if (a == 1) {

			printf("factor\n");

			check = 1;

		}









		if (b % a == 0 && check == 0) {

			printf("factor\n");

			check = 1;

		}



		if (a % b == 0 && check == 0) {

			printf("multiple\n");

			check = 1;

		}



		if (check == 0) {

			printf("neither\n");

		}





		scanf("%d", &a);

		scanf("%d", &b);

		check = 0;

	}



	return 0;

}