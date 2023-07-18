#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다}

//an+b>cn   b>(c-a)n

int main(void)

{

	int a1, a2, c, n0, flag = 1;

	scanf("%d %d %d %d", &a1, &a2, &c, &n0);



	while (flag == 1 && n0 <= 100) {

		if (a2 > (c - a1) * n0)

			flag = 0;

		n0++;

	}



	printf("%d", flag);

	return 0;

}