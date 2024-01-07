#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int age;
	char name[101];
}Member;
int compare(const void* a, const void* b)
{
	int ageA = ((Member*)a)->age;
	int ageB = ((Member*)b)->age;

	if (ageA <= ageB)
		return -1;
	else
		return 1;
}
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	Member* m = (Member*)malloc(sizeof(Member) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i].age);
		scanf("%s", m[i].name);
	}

	qsort(m, n, sizeof(Member), compare);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", m[i].age, m[i].name);

	free(m);
}

/*
¹Ý·Ê
10
21 d
21 a
21 e
21 c
21 h
20 w
20 z
20 a
20 h
21 r
*/