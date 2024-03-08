#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	long long n = 0, sum = 0, k = 0, remove = 0;

	scanf("%lld", &n);

	long long* save = (long long*)malloc(sizeof(long long) * n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &k);
		
		if (k == 0) {
			sum -= save[remove - 1];
			remove--;
		}
		else {
			sum += k;
			save[remove++] = k;
		}
	}

	printf("%lld", sum);
}