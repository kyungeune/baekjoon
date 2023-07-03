#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	long long a, b, goal, sum = 0, start = 0;

	scanf("%llu %llu %llu", &a, &b, &goal);

	start = goal - a;
	while (start%(a-b)!=0) {
		start--;
	}
	sum = start / (a - b);

	while (start < goal) 
	{
		start += a;
		if (start >= goal) {
			sum++; //다음날이당
			break;
		}
		start -= b;
		sum++; //하루가 지났당
	}
	printf("%lld", sum);

	return 0;
}