#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[102];
	int end = 0;

	while (end == 0) {
		// scanf("%s", s);
		fgets(s, sizeof(s), stdin);

		int len = strlen(s);
		int yes = 1;
		int miniend = 0;

		int small = 0, big = 0, l = 0;
		int latest[102] = { 0 };// ( = 1, [ = 2


		for (int i = 0; i < len; i++) {
			if (strcmp(s, ".\n") == 0) {
				end = 1;
				break;
			}

			if (s[i] == '(') { // (
				small++;
				latest[l++] = 1;
			}
			else if (s[i] == ')' && small == 0) { // ( 없는데 ) 나온 경우
				yes = 0;
				break;
			}
			else if (s[i] == ')' && latest[l - 1] != 1) { // 최근께 ( 이 아닌 경우
				yes = 0;
				break;
			}
			else if (s[i] == ')') { // ( 있는데 ) 나온 경우
				small--;
				l--;
			}

			if (s[i] == '[') { // (
				big++;
				latest[l++] = 2;
			}
			else if (s[i] == ']' && big == 0) { // ( 없는데 ) 나온 경우
				yes = 0;
				break;
			}
			else if (s[i] == ']' && latest[l - 1] != 2) { // 최근께 ( 이 아닌 경우
				yes = 0;
				break;
			}
			else if (s[i] == ']') { // ( 있는데 ) 나온 경우
				big--;
				l--;
			}

			if (i == len - 1 && s[len - 2] != '.') {
				fgets(s, sizeof(s), stdin);
				i = -1;
			}
		}

		if (end == 1)break;

		if (yes == 1)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}