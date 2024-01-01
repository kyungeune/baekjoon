#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int n = 0;
	char** s = (char**)malloc(sizeof(char*) * n);
	int len[50][50] = { 0 }; // 길이, 해당하는 i값
	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%s", s[i]);
		len[strlen(s[i])][i] = 1;
	}
	// 수정
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (len[i][j] == 0) {
				break;
			}
			else {
				
			}
		}
	}


	// 출력
	for (int i = 0; i < n; i++) {
		
	}
}