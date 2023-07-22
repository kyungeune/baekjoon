#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//why don't you code 갈아엎기?
int main(void)
{
	int n, m, cnt = 0, sum = 0, bMin=100, cMin=100, sumi = 0;
	int** A;
	int* B;
	int* C;
	char s[50];
	scanf("%d %d", &n, &m);

	A = (int**)malloc(sizeof(int*) * n);
	B = (int*)malloc(sizeof(int) * n);
	C = (int*)malloc(sizeof(int) * n);
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
		int Mini = 100, eJun = 100;
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
				if (A[i][j] != 'B')
					sum++;
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				if (A[i][j] != 'W')
					sum++;
			}

			if (j == 7) {
				Mini = sum;
				eJun = A[i][j];
			}
			if (j > 7) {
				if (sum - eJun < Mini)
					Mini = sum - eJun;
				eJun += A[i][j - 7];
			}
		}

		sum = Mini;

		if (i == 7)
			bMin = sum;

		if (i == 0)
			B[i] = sum;
		else
			B[i] = sum - sumi;
		sumi += B[i];
	}


	for (int i = 0; i < n; i++)
		printf("%d ", B[i]);

	sumi = 0;
	for (int i = 0; i < n; i++) { //B먼저
		int Mini=100, eJun=100;
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

			if (j == 7) {
				Mini = sum;
				eJun = A[i][j];
			}
			if (j > 7) {
				if (sum - eJun < Mini)
					Mini = sum - eJun;
				eJun += A[i][j - 7];
			}
		}

		cnt = Mini;

		if (i == 7)
			cMin = cnt;


		if (i == 0)
			C[i] = cnt;
		else
			C[i] = cnt - sumi;
		sumi += C[i];
	}




	for (int i = 1; i < n - 8; i++) {
		int imsiB = 0;
		int imsiC = 0;

		for (int j = i; j < i + 8; j++) {
			imsiB += B[j];
			imsiC += C[j];
		}

		if (imsiB < bMin)
			bMin = imsiB;
		if (imsiC < cMin)
			cMin = imsiC;
	}

	if (bMin < cMin)
		printf("%d", bMin);
	else
		printf("%d", cMin);



	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(B);
	free(C);
	return 0;
}