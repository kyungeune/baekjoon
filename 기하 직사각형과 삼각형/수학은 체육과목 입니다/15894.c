#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	long long n, ans=0;

	scanf("%llu", &n);

	for (long long i = 0; i < n; i++) {
		ans += 4 * (i + 1);
		ans -= i * 4;
	}

	printf("%llu", ans);

	return 0;
}