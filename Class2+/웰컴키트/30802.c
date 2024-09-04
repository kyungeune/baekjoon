#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int t = 0, p = 0, m = 0, n = 0, sum = 0, tn = 0, cnt = 0;

	scanf("%d", &n);

	int k[6] = { 0 };

	for (int i = 0; i < 6; i++) {
		scanf("%d", &k[i]);
	}

	scanf("%d %d", &t, &p);
	
	for (int i = 0; i < 6; i++) {
		tn += ((k[i] + t) / t - 1);
		if (k[i] % t != 0) 
			tn++;
	}

	printf("%d\n", tn);  // t개수, pen개수, 나머지개수

	printf("%d %d", (n + p) / p - 1, (n + p) % p);

	return 0;
}