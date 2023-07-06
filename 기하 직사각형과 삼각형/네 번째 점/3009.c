#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int x[2] = { 0 }, y[2] = { 0 }, xCnt[2] = { 0 }, yCnt[2] = { 0 };	int a, b;



	for (int i = 0; i < 4; i++) {

		if (i == 3) {

			if (xCnt[0] == 1)

				printf("%d ", x[0]);

			else

				printf("%d ", x[1]);

			if (yCnt[0] == 1)

				printf("%d", y[0]);

			else

				printf("%d ", y[1]);

		}

		else {

			scanf("%d %d", &a, &b);

			if (x[0] == 0 || x[0] == a) {

				x[0] = a;

				xCnt[0]++;

			}
			else {

				x[1] = a;

				xCnt[1]++;

			}

			if (y[0] == 0 || y[0] == b) {

				y[0] = b;

				yCnt[0]++;

			}
			else {

				y[1] = b;

				yCnt[1]++;

			}

		}

	}





}