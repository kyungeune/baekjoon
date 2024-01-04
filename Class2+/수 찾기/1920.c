#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int search(long long save[], int st, int ed, long long find)
{
	int mid = -1;

	while (st <= ed) {
		mid = (st + ed) / 2;

		if (save[mid] >= find) {
			if (save[mid] == find)
				return 1;
			ed = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return 0;
}
int main(void)
{
	int n = 0, m = 0;
	scanf("%d", &n);
	long long* save = (long long*)malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &save[i]);
	}
	// save 정렬
	qsort(save, n, sizeof(long long), compare); // stdlib 헤더파일에 존재, 비교함수만 추가적으로 짜면 됨
	
	// save 탐색 결과 출력
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		long long k;
		scanf("%lld", &k);
		printf("%d\n", search(save, 0, n - 1, k));
	}

	free(save);
	return 0;
}