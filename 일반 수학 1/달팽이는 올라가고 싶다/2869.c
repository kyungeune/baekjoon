#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	long long a, b, goal, k, namuzi, sum = 0;

	scanf("%llu %llu %llu", &a, &b, &goal);

	if(goal / (a - b) + a - b<=goal)
		printf("%lld", goal / (a - b) + 1);
	else
		printf("%lld", goal/(a - b)+a-b - a);

	return 0;

}