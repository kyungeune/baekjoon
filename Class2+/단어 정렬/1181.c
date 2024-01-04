#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b)
{
	const char* str1 = *(const char**)a;
	const char* str2 = *(const char**)b;

	int aLen = strlen(str1);
	int bLen = strlen(str2);

	if (aLen < bLen)
		return -1;
	else if (aLen > bLen)
		return 1;
	else
		return strcmp(str1, str2);
}
int is_exist(char** s, int n, char* this, int k)
{
	for (int i = k + 1; i < n; i++)
	{
		if (strcmp(s[i], this) == 0)
			return 1;
	}
	return 0;
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	char** s = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
		s[i] = (char*)malloc(sizeof(char) * 51);

	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	qsort(s, n, sizeof(char*), compare);
	for (int i = 0; i < n; i++) {
		if (is_exist(s, n, s[i], i) == 0)
			printf("%s\n", s[i]);
	}

	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
}