#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	int A[3] = { 1 };
	int Equilateral = 0, Isosceles = 0, Scalene = 0, Invalid = 0;

	while (A[0] != 0) {
		for (int i = 0; i < 3; i++) //입력받기
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

		if (A[0] == 0)
			break;

		if (A[0] + A[1] <= A[2])
			printf("Invalid\n");
		else if (A[0] == A[2])
			printf("Equilateral\n");
		else if (A[0] == A[1] || A[1] == A[2])
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}
}