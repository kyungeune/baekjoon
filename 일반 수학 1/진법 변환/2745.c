#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char n[100001];
	int size=0;
	long long answer = 0, b, bk = 1;

	scanf("%s %llu", n, &b);

	for (size = 0; n[size] != '\0'; size++);

	for (int i = size - 1; i>=0; i--) {
		if (n[i] >= 48 && n[i] <= 57) { //숫자면
			answer += bk * (n[i] - 48);
		}
		else { //알파벳이면
			answer += bk * (n[i] - 55);
		}
		bk *= b;
	}

	printf("%lld", answer);
}