#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	long long sam = 1, ans = 0;
	int n;

	scanf("%d", &n);
	char* c = (char*)malloc(sizeof(char) * (n + 1));
	
	scanf("%s", c);

	for (int i = 0; i < n; i++) {

		// printf("%d\n", ans);
		ans *= (sam * (c[i] - 96)) % 1234567891;
		sam *= 31;
	}

	printf("%lld", ans % 1234567891);


	free(c);
	return 0;
}