#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cal(double m)
{
	int cnt = 0;

	if (m >= 25) {
		while (m >= 25) {
			cnt++;
			m -= 25;
		}
	}
	printf("%d ", cnt);
	cnt = 0;

	if (m >= 10) {
		while (m >= 10) {
			cnt++;
			m -= 10;
		}
	}
	printf("%d ", cnt);
	cnt = 0;

	if (m >= 5) {
		while (m >= 5) {
			cnt++;
			m -= 5;
		}
	}
	printf("%d ", cnt);
	cnt = 0;

	if (m >= 1) {
		while (m >= 1) {
			cnt++;
			m -= 1;
		}
	}
	printf("%d\n", cnt);
	cnt = 0;
}

int main(void)
{
	double n, c;

	scanf("%lf", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &c);
		cal(c);
	}

	return 0;
}