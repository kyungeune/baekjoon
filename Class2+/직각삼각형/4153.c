#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a = -1, b = -1, c = -1;

	while (a != 0) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
			break;
		// �ݷ� 3 5 4
		// ���� ū ��(x) ���ϴ� ����
		int y = (a > b) ? a : b;
		int z = (a > c) ? a : c;
		int w = (b > c) ? b : c;
		int x = (y > z) ? y : z;
		y = (y < z) ? y : z;
		y = (y < w) ? y : w;
		// z�� ���� ���� ���� ����־�� ��
		// ���� ���� �� ���ϴ� ���� �Ȱ��� �ݺ�
		int e = (a < b) ? a : b;
		int f = (a < c) ? a : c;
		int d = (e < f) ? e : f; // ���� ���� ��
		z = d;

		if (x * x == y * y + z * z)
			printf("right\n");
		else
			printf("wrong\n");
	}
}