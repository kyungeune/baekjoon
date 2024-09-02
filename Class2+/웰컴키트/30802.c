#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int t = 0, p = 0, m = 0, n = 0, sum = 0, tn = 0, cnt = 0;

	scanf("%d", &n);

	int* k = (int*)malloc((n+1) * sizeof(int));

	for (int i = 0; i < n + 1; i++)
		k[i] = 0;

	//if (k == NULL) {
	//	printf("1\n1 0");
	//	return 0;
	//}

	for (int i = 0; sum < n;) {
		scanf("%d", &m);

		if (m != 0) {
			sum += m;
			k[i++] = m;
			cnt++;
		}
	}

	scanf("%d %d", &t, &p);
	
	for (int i = 0; i < cnt; i++) {
		int imsi = k[i];

		if (imsi < t)
			tn++;
		else {
			tn += (int)(imsi / t);
			if (imsi % t != 0)
				tn++;
		}

	}

	printf("%d\n%d %d", tn, (int)(sum / p), (int)(sum % p));  // t개수, pen개수, 나머지개수

	free(k);

	return 0;
}