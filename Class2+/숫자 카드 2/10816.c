#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int cnt;
}Have;
int main(void)
{
	int n = 0, m = 0;
	scanf("%d", &n);
	Have* h = (Have*)malloc(sizeof(Have) * 20000001);
	for (int i = 0; i < 20000001; i++)
		h[i].cnt = 0;

	for (int i = 0; i < n; i++) {
		int imsi;
		scanf("%d", &imsi);
		if (imsi < 0) {
			imsi += 30000000;
			h[imsi].cnt++;
		}
		else
			h[imsi].cnt++;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int imsi;
		scanf("%d", &imsi);
		if (imsi < 0) {
			imsi += 30000000;
			printf("%d ", h[imsi].cnt);
		}
		else
			printf("%d ", h[imsi].cnt);
	}

	free(h);
	return 0;
}