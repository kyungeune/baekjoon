#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	long long neww;
	long long k;
	long long si = 0;
	char s[100001];

	scanf("%llu %llu", &neww, &k);

	while (neww > 0) {
		s[si++] = neww % k;
		neww /= k;
	}
	
	for (long long i = si - 1; i >= 0; i--) {
		if (s[i] >= 0 && s[i] <= 9)
			printf("%c", s[i]+'0');
		else
			printf("%c", s[i] - 10 + 'A');
	}
}