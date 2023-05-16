#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i = 0, check = 97, is = 0;
	char s[101];

	scanf("%s", s);

	while (check<123){
		is = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == check) {
				printf("%d ", i);
				is = 1;
				break;
			}
		}
		if (is == 0)
			printf("-1 ");
		check++;
	}

	return 0;
}