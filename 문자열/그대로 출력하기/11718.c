#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char why[10001]="";
	char s[101]="";

	for (int i = 0; i < 100; i++)
	{
		fgets(s, sizeof(s),stdin);
		strcat(why, s);

		if (s[strlen(s)-1] == '\n')
			break;
	}

	//strcat(why, '\0');
	printf("%s", why);

	return 0;
}