#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	long long sam = 0, ans = 0;
	int n;

	scanf("%d", &n);
	char* c = (char*)malloc(sizeof(char) * (n + 1));
	
	scanf("%s", c);

	for (int i = 0; i < n; i++) {

		sam = (sam + 31) % 1234567891;
		ans = (ans + (sam * (c[i] - 36)) % 1234567891) % 1234567891;
	}
	

	printf("%lld", ans);


	free(c);
	return 0;
}