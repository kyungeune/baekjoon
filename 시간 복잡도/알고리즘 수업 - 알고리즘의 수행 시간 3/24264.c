#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*	MenOfPassion(A[], n) {

sum <- 0;

for i <- 1 to n

	for j <- 1 to n

		sum <- sum + A[i] ¡¿ A[j]; # ÄÚµå1

return sum;

}

*/

long long H(long long A[], long long n)

{

	long long sum = 0;

	for (int i = 0; i < n; i++)

		for (int j = 0; j < n; j++)

			sum += 1;

	return sum;

}

int main(void)

{

	long long A[500000] = { 0 }, n;

	scanf("%d", &n);

	printf("%llu\n2", H(A, n));

}