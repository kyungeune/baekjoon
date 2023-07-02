#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	long long num, sum = 1, i;	scanf("%llu", &num);



	for (i = 1; ; i++) {

		sum += 6 * i;

		if (sum >= num)

			break;

	}



	if (num == 1)

		i = 0;

	printf("%lld", i + 1);

	return 0;

}