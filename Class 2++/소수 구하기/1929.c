#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void input(int a[], int n)
{
	a[0] = 0;
	for (int i = 0; i < n; i++)
		a[i + 1] = i + 1;
}
// ¹Ý·Ê 3 4
int main(void)
{
	int m, n;
	int* sosu = (int*)malloc(sizeof(int) * 1000001);

	scanf("%d %d", &m, &n);

	input(sosu, 1000000);

	for (int i = 2; i <= n; i++) {
		if (sosu[i] == 0)
			continue;
		
		for (int j = 2; j * i <= n; j++) {
			sosu[j * i] = 0;
		}

		if (i * i >= n) // for¹® ¸Ç µÚ·Î º¸³¿, ¹Ý·Ê 3 4
			break;
	}

	sosu[1] = 0;
	for (int i = m; i <= n; i++) {
		if (sosu[i] != 0)
			printf("%d\n", sosu[i]);
	}

	free(sosu);

	return 0;
}