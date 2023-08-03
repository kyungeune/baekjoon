#include <stdio.h>
int main(void)
{
	int A[n];
	int B[k] = { 0, }; //처음은 0으로 초기화 //C[0], C[1], ... C[k]
	for (int i = 0; i <= n; i++)
		B[A[i]]++;
	for (int c = 1, i = 0; i <= k; i++) {
		for (int j = 0; j < B[i]; j++) {
			A[c++] = i;
		}
	}
}