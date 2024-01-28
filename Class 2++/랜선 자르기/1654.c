#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
// 2 4 50 200
// 2 2 4 1
// N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 
int main(void)
{
	int n = 0, k = 0, end = 0, max = 0, minus = 0;
	int* l = (int*)malloc(sizeof(int) * 1000000);

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}

	qsort(l, n, sizeof(int), compare);

	int a = l[0];

	while (a<=l[0] && a <= l[n - 1]) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += l[i] / a;
		}

		if (sum >= k) {
			end = 1;
			if (max < a)
				max = a;
			if (minus == 1)
				a--;
			else
				a++;
		}
		else {
			a--;
			minus = 1;
			if (end == 1)
				break;
		}
	}

	printf("%d", max);
	
	free(l);

	return 0;
}