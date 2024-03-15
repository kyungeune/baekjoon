#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int x;
	int y;
}Member;
int compare(const void* a, const void* b)
{
	int w = ((Member*)a)->x;
	int wy = ((Member*)a)->y;
	int z = ((Member*)b)->x;
	int zy = ((Member*)b)->y;

	if (wy < zy)
		return -1;
	else if (wy == zy) {
		if (w < z)
			return -1;
		else
			return 1;
	}
	else
		return 1;
}
//int compare(const void* a, const void* b)
//{
//	int diff = ((Member*)a)->x - ((Member*)b)->x;
//	return (diff != 0) ? diff : ((Member*)a)->y - ((Member*)b)->y; // x값의 차이가 있으면 그 차이를 반환하고, x값의 차이가 없으면 y값의 차이를 반환하라..
//}
int main(void)
{
	int n = 0;
	scanf("%d", &n);

	Member* m = (Member*)malloc(sizeof(Member) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i].x);
		scanf("%d", &m[i].y);
	}

	qsort(m, n, sizeof(Member), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", m[i].x, m[i].y);
	}

	free(m);
}