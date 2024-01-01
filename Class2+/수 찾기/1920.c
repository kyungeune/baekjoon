#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n = 0, m = 0;
	scanf("%d", &n);
	long long* save = (long long*)malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++) {
		long long k;
		scanf("%lld", &k);
		save[i] = k;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		long long k = 0;
		int flag = 0;
		scanf("%lld", &k);
		for (int j = 0; j < n; j++) {
			if (save[j] == k) {
				flag = 1;
				printf("1\n");
				break;
			}
		}
		if (flag == 0)
			printf("0\n");
	}

	free(save);
	return 0;
}