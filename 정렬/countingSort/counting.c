#include <stdio.h>
int main(void)
{
	int A[n];
	int B[k] = { 0, }; //ó���� 0���� �ʱ�ȭ //C[0], C[1], ... C[k]
	for (int i = 0; i <= n; i++)
		B[A[i]]++;
	for (int c = 1, i = 0; i <= k; i++) {
		for (int j = 0; j < B[i]; j++) {
			A[c++] = i;
		}
	}
}