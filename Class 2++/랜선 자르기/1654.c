#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long compare(const void* a, const void* b)
{
	return (*(long long*)a - *(long long*)b);
}
long long binarySearch(long long save[], long long st, long long ed, long long find)
{
	long long mid = -1;

	while (st <= ed) {
		mid = (st + ed) / 2;

		if (save[mid] >= find) {
			if (save[mid] == find)
				return 1;
			ed = mid - 1;
		}
		else
			st = mid + 1;
	}
	return 0;
}
// 2 4 50 200
// 2 2 4 1
// 2 2 600 1000
// 2 2 600 1200
// 4 4 50 50 50 50
// 2 3 6 7 => 3 3 3 3
// 3 7 87 67 97
// 5 4 2147483645 2147483645 2147483645 2147483645 2147483646
// N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 
long long main(void)
{
	long long n = 0, k = 0, end = 0, max = 0, same = 0, minus = 0;
	long long* l = (long long*)malloc(sizeof(long long) * 1000000);

	scanf("%lld %lld", &n, &k);

	for (long long i = 0; i < n; i++) {
		scanf("%lld", &l[i]);
	}

	qsort(l, n, sizeof(long long), compare);

	long long a = l[0];

	while (a > 0) {
		long long sum = 0;

		for (long long i = 0; i < n; i++) {
			sum += l[i] / a;
		}

		if (sum == k) {
			same = 1;
			if (max < a)
				max = a;

			if (minus == 1)
				a--;
			else
				a++;
		}
		else if (sum > k) {
			if (same == 1)
				break;

			if (a == l[0] && same == 0) { // 초기
				max = a;
				break;
			}
			if (minus == 1 && same == 0) {
				max = a;
				break;
			}
			a++;
		}
		else {
			if (same == 1)
				break;
			a--;
			minus = 1;
		}
	}

	printf("%lld", max);

	free(l);

	return 0;
}
