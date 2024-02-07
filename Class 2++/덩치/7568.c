#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct person {
	int height, weight, num;
}person;
int dungchi(person* p, int n, int me)
{
	int sum = 0;

	// 자신보다 덩치가 큰 사람의 개수
	for (int i = 0; i < n; i++) {
		if (i == me)
			continue;

		if (p[i].height > p[me].height && p[i].weight > p[me].weight)
			sum++;
	}
	
	return sum + 1;
}
int main(void)
{
	int n, smallest = 201;
	scanf("%d", &n);

	person* p = (person*)malloc(sizeof(person) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].weight, &p[i].height);
	}

	for (int i = 0; i < n; i++) {
		p[i].num = dungchi(p, n, i);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", p[i].num);
	}

	free(p);
	return 0;
}