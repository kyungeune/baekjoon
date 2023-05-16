#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int A[26], a = 0, sum = 0;
	char k = 65;
	char s[1000];
	scanf("%s", s);

	//printf("%c ", s[0]);

	for (int i = 3; k < 91; i++) { //A 배열에 걸리는 시간넣기
		for (int j = 0; j < 4; j++) {
			if (j == 3) {
				if (k == 83 || k == 90) {
					A[a++] = i;
					k++;
					break;
				}
				else
					break;
			}
			A[a++] = i;
			k++;
		}
	}

	for (int i = 65; i < 91; i++) { //배열에 있는 숫자들 더하기
		for (int j = 0; j < strlen(s); j++) {
			if (i == s[j]) {
				sum += A[i-65];
			}
		}
	}

	printf("%d", sum);
}