#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int* S, *N, n, i, j, thereis = 0, k=0;

	S = (int*)malloc(sizeof(int) * 28);
	N = (int*)malloc(sizeof(int) * 2);

	for (i = 0; i < 28; i++)
		scanf("%d", &S[i]);

	for (i = 1; i <= 30; i++) {
		thereis = 0;
		for (j = 0; j < 28; j++)
			if (S[j] == i) {
				thereis = 1;
				break;
			}
		if (thereis == 0)
			N[k++] = i;
	}

	if (N[0] < N[1])
		printf("%d\n%d", N[0], N[1]);
	else
		printf("%d\n%d", N[1], N[0]);

	free(S);
	free(N);
	return 0;
}