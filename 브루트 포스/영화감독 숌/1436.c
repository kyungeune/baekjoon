#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, count=0, i;
	scanf("%d", &n);

	for (i = 666; ; i++)
	{
		int k = i, cnt=0, flag = 0;
		while (k > 0)
		{
			if (k % 10 == 6) {
				cnt++;
				flag = 1;
				if (cnt >= 3)
					break;
			}
			else {
				if (flag == 1)
					cnt = 0;
				flag = 0;
			}
			k /= 10;
		}
		if(cnt>=3)
			count++;
		if (count == n)
			break;
	}

	printf("%d", i);
}