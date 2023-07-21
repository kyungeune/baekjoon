#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m, cnt = 0, sum = 0;
	int** A;
	char s[50];
	scanf("%d %d", &n, &m);

	A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		A[i] = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			A[i][j] = s[j];
			/*printf("%c\n", A[i][j]);*/
		}
		//if(i!=n-1)
		//	while (getchar() != '\n');
	}
	
	for (int i = 0; i < n; i++) { //W먼저
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (A[i][j] != 'W')
					sum++;
			}
			else if (i % 2 == 0 && j % 2 != 0) {
				if (A[i][j] != 'B')
					sum++;
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				//if (A[i][j] != 'B')
					sum++;
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				if (A[i][j] != 'W')
					sum++;
			}
		}
	}

	for (int i = 0; i < n; i++) { //B먼저
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (A[i][j] != 'B')
					cnt++;
			}
			else if (i % 2 == 0 && j % 2 != 0) {
				if (A[i][j] != 'W')
					cnt++;
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				if (A[i][j] != 'W')
					cnt++;
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				if (A[i][j] != 'B')
					cnt++;
			}
		}
	}





	if (cnt < sum)
		printf("%d", cnt);
	else
		printf("%d", sum);



	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}