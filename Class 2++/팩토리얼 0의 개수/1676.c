#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	long long n, sum = 0, e = 0, o = 0;
	
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++) {
		int imsi = i;

		if (imsi % 2 == 0) {
			while (imsi >= 2 && imsi % 2 == 0) {
				imsi /= 2;
				e++;
			}
		}

		imsi = i;

		if (imsi % 5 == 0) {
			while (imsi >= 5 && imsi % 5 == 0) {
				imsi /= 5;
				o++;
			}
		}

	}

	while (e > 0 && o > 0) {
		sum++;
		e--;
		o--;
	}

	printf("%lld", sum);
}