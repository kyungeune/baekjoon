#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person{
	char name[21];
}Person;
int compare(const void* a, const void* b)
{
	int len = (strlen(((Person*)a)->name) < ((Person*)b)->name) ? strlen(((Person*)a)->name) : strlen(((Person*)b)->name);

	for (int i = 0; i < len; i++) {
		int nameA = ((Person*)a)->name[i];
		int nameB = ((Person*)b)->name[i];

		if (nameA < nameB)
			return -1;
		else if(nameA > nameB)
			return 1;
	}

	return -1; // 이게 1이면 틀림.

}
int main(void)
{
	int n, m, sum = 0, bdd = 0;

	scanf("%d %d", &n, &m);
	Person* d = (Person*)malloc(sizeof(Person) * (n+m));
	Person* db = (Person*)malloc(sizeof(Person) * n);

	for (int i = 0; i < n + m; i++)
		scanf("%s", d[i].name);

	qsort(d, n+m, sizeof(Person), compare);

	for (int i = 0; i < n+m; i++) {
		if (strcmp(d[i].name, d[i + 1].name) == 0 && i < n + m - 1) {
			sum++;
			strcpy(db[bdd].name, d[i].name);
			bdd++;
		}
	}

	printf("%d\n", sum);


	for (int i = 0; i < bdd; i++)
		printf("%s\n", db[i].name);

	return 0;
}