#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char s[100000];
	int flag = 0; // �ʱⰪ
	while (flag>=0) {
		scanf("%s", s);
		if (s[0] == '0' && strlen(s) == 1)
			break;
		flag = 0;
		for (int i = 0; i < strlen(s) / 2; i++) {
			if (s[i] != s[strlen(s) - i - 1]) {
				flag = 1;
				printf("no\n");
				break;
			}
		}
		if (flag == 0)
			printf("yes\n");
	}

}