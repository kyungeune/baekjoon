#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	int A[3] = { 0 };
	int Equilateral = 0, Isosceles = 0, Scalene = 0, Invalid = 0;

	for (int i = 0; i < 3; i++) //�Է¹ޱ�
	{
		scanf("%d", &A[i]);
		for (int j = 0; j < i; j++) { //ũ�� ������ ����
			if (A[j] > A[i]) {
				int temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
	}
}