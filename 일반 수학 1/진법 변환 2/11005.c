#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char answer[100001];
	int size=0, a = 0;
	long long n = 0, b, bk = 1;

	scanf("%llu %llu", &n, &b);

	while (n > 0) {
		n -= bk;
	}
	answer[a] = '\0';

	printf("%s", answer);
}