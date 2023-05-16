#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	int i, j, max = -1, maxNum = 0, count = 0, same = 0, z, pass = 0, length = 0;
	char s[1000001] = "";
	int d[26] = {0}; //대문자 개수 모음 zone
	scanf("%s", s);

	length = strlen(s);

	for (i = 0; i < length; i++) //대문자로 통일
	{
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		int k = s[i];
		d[k - 65] += 1;
	}

	for (i = 0; i < length; i++) //대문자만 존재
	{
		if (s[maxNum]!=s[i]&& d[s[i] - 65]==max) {
			same = 1;
		}

		if (d[s[i] - 65] > max) {
			max = d[s[i] - 65];
			maxNum = i;
			same = 0;
		}
	}

	if (same == 1)
		printf("?");
	else
		printf("%c", s[maxNum]);

	return 0;
}