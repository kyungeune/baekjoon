#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int n = 0, cnt = 0;
	char moon[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cnt = 0;
		scanf("%s", moon);
		for (int j = 0; moon[j] != '\0'; j++) {
			if (cnt == 0 && moon[j] == ')') {
				cnt++;
				break;
			}
			if (moon[j] == '(')
				cnt++;
			else
				cnt--;
		}
		if (cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}