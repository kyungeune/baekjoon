#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct nums{
	long long cnt, num;
}nums;
int compare(const void* a, const void* b)
{
	if (*(long long*)a > *(long long*)b)
		return 1;
	else if (*(long long*)a < *(long long*)b)
		return -1;
	else
		return 0;
}
int compare2(const void* a, const void* b)
{
	if (((nums*)a)->num > ((nums*)b)->num)
		return 1;
	else if (((nums*)a)->num < ((nums*)b)->num)
		return -1;
	else
		return 0;
}
int main(void)
{
	long long n, sum = 0, freq = 0, min = 4001, max = -4001, ai = 0, cntMax = 0; 
	scanf("%lld", &n);
	nums* a = (nums*)malloc(sizeof(nums) * n);
	
	for (long long i = 0; i < n; i++) {
		long long exist = 0, imsi = 0;
		scanf("%lld", &imsi);

		for (long long j = 0; j < ai; j++) {
			if (a[j].num == imsi) {
				a[j].cnt++;
				exist = 1;
				break;
			}
		}

		if (exist == 0) {
			if (imsi < min)
				min = imsi;
			if (imsi > max)
				max = imsi;
			a[ai].num = imsi;
			a[ai].cnt = 1;
			if (a[ai].cnt > cntMax)
				cntMax = a[ai].cnt;
			ai++;
		}

		sum += imsi;
	}

	// freq
	long long* fre = (long long*)malloc(sizeof(long long) * n);
	int f = 0;
	for (int i = 0; i < ai; i++) {
		if (a[i].cnt == cntMax)
			fre[f++] = a[i].num;
	}
	qsort(fre, f, sizeof(long long), compare);
	qsort(a, ai, sizeof(nums), compare2);
	
	// 평균+반올림
	printf("(double)sum %llf\n", (double)sum);
	printf("(double)sum / n%llf\n", (double)sum / n);
	printf("%f\n", round((double)sum / n));
	// 미드
	printf("%lld\n", a[ai/2].num); // 홀수이므로 걍 가운데 값
	// 최빈
	if (f == 1)
		printf("%lld\n", fre[0]);
	else
		printf("%lld\n", fre[1]); // cnt 최대인애들 long long 배열에 모아놓고 qsort하고 1번째값 출력
	// 범위
	printf("%lld\n", max - min); // 하나인경우 0, 최댓값-최솟값
	
	free(a);
	return 0;
}