#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long realSum = -1;
void pick(long long A[], long long picked[], long long n, long long m, long long toPick)
{
	long long sum = 0;

	for (long long i = 0; i < 3 - toPick; i++) {
		sum += A[picked[i]];
		//printf("%llu ", A[picked[i]]);
		if (sum > m)
			return;
	}

	if (toPick == 0) {
		sum = 0;

		for (long long i = 0; i < 3; i++) {
			sum += A[picked[i]];
			if (sum > m)
				return;
		}

		if (sum > realSum)
			realSum = sum;
	}

	long long smallest = 0;

	if (toPick == 3)
		smallest = 0;
	else
		smallest = picked[3-toPick-1];

	for (long long i = smallest; i < n; i++) {
		long long j, flag = 0;
		for (j = 0; j < 3-toPick; j++)
			if (picked[j] == i)
				flag = 1;
		if (flag == 1)	continue;
		picked[3-toPick] = i;
		pick(A, picked, n, m, toPick - 1);
	}
}

int main(void)
{
	long long n, m;
	long long* A;
	long long picked[3]={0,0,0};

	scanf("%lld %lld", &n, &m);

	A = (long long*)malloc(sizeof(long long) * n);

	for (long long i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}

	pick(A, picked, n, m, 3);

	printf("%lld", realSum);

	free(A);
	return 0;
}