#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	long long i = 0, n, sum = 0, count = 0;

	scanf("%llu", &n);

	for (i = 1; i <= n; i++)
	{
		sum += i;
		if (sum >= n)
			break;
	}
	
	sum = sum - i + 1;
	while (n > sum) {
		count++;
		sum++;
	}
	
	if (i % 2 == 0) {
		printf("%lld/%lld", count + 1, i - count);
	}
	else {
		printf("%lld/%lld", i - count, count + 1);
	}

	return 0;

}