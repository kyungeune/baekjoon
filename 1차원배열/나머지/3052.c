#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int* S, * N, i, j, count = 0, same = 0, allSame = 0, n=0, z=0, alone=0;

	S = (int*)malloc(sizeof(int) * 10);
	N = (int*)malloc(sizeof(int) * 10);

	for (i = 0; i < 10; i++) {
		scanf("%d", &S[i]);
		S[i] %= 42;
	}

	for (i = 0; i < 10; i++) {
		allSame = 0;
		alone = 0;
		for (j = 0; j < 10; j++) {

			if (S[i] == S[j])
				allSame++;

			if (S[i] == S[j] && i != j) {
				same = 0;
				alone = 1;
				for (z = 0; z < n; z++)
					if (N[z] == S[j])
						same = 1;
				if (same == 0) {
					N[n++] = S[j];
					count++;
				}
			}

		}
		
		if (alone == 0)
			count++;
		if (allSame == 10) {
			count = 1;
			break;
		}
	}
	
	printf("%d", count);

	free(S);
	free(N);
	return 0;
}