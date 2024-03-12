#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, k;
	int save[41][2] = {0};

	scanf("%d", &n);

	for (int i = 0; i <= 40; i++) { // 값 넣기
		if (i == 0) {
			save[i][0] = 1;
			save[i][1] = 0;
		}
		else if (i == 1) {
			save[i][0] = 0;
			save[i][1] = 1;
		}
		else if (i == 2) {
			save[i][0] = 1;
			save[i][1] = 1;
		}
		else {
			save[i][0] = save[i - 1][0] + save[i - 2][0];
			save[i][1] = save[i - 1][1] + save[i - 2][1];
		}
	}

	for (int i = 1; i <= n; i++) { // 출력
		scanf("%d", &k);
		printf("%d %d\n", save[k][0], save[k][1]);
	}
}