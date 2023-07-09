#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	int A[3] = { 0 };
	int Equilateral = 1, Isosceles = 0, Scalene = 0, Error = 0;

	for (int i = 0; i < 3; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < 3; i++)
	{
		Error += A[i];
		for (int j = 0; j < 3; j++) {
			if (j != i) {
				if (A[i] == A[j])
					Isosceles = 1;
				else
					Equilateral = 0;
			}
		}
	}

	if (Error != 180)
		printf("Error");
	else if (Equilateral == 1)
		printf("Equilateral");
	else if (Isosceles == 1)
		printf("Isosceles");
	else
		printf("Scalene");
}