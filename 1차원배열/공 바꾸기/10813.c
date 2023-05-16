#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* B, i, n, count;
	scanf("%d", &n);
	scanf("%d", &count);

	B = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		B[i] = (i+1);
	}//BÃÊ±âÈ­

	for (i = 0; i < count; i++) {
		int first; scanf("%d", &first);
		int last; scanf("%d", &last);
		first -= 1;
		last -= 1;
		if (first != last) {
			int temp = B[first];
			B[first] = B[last];
			B[last] = temp;
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", B[i]);

	free(B);
	return 0;
}