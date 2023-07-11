#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int A[3];	for (int i = 0; i < 3; i++) //입력받기

	{

		scanf("%d", &A[i]);

		for (int j = 0; j < i; j++) { //크기 순으로 정렬

			if (A[j] > A[i]) {

				int temp = A[j];

				A[j] = A[i];

				A[i] = temp;

			}

		}

	}



	if (A[1] == A[2] || A[0] + A[1] - 1 > A[2])

		printf("%d", (A[0] + A[1] + A[2]));

	else

		printf("%d", (A[0] + A[1]) * 2 - 1);



}