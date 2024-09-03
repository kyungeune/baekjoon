#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int t = 0, p = 0, m = 0, n = 0, sum = 0, tn = 0, cnt = 0;

	scanf("%d", &n);

	int* k = (int*)malloc((n+1) * sizeof(int));

	for (int i = 0; i < n + 1; i++) // 초기화
		k[i] = 0;

	for (int i = 0; sum < n;) { // 지금까지 입력받은 것의 합계(sum)가 n미만일때 계속 입력받기
		scanf("%d", &m); // 입력

		if (m != 0) { // 0이 아닌 경우에만 입력받기
			k[cnt++] = m; // cnt = 입력받은 것의 개수(0 제외)
		}
	}

	scanf("%d %d", &t, &p);
	
	for (int i = 0; i < cnt; i++) {
		int imsi = k[i];

		if (imsi < t)
			tn++;
		else {
			tn += (int)(imsi / t); // 0이 아닌 것들을 입력받았기 때문에 
			if (imsi % t != 0) // 나머지가 존재할 경우(=t의 배수가 아닐 경우)
				tn++;
		}

	}

	printf("%d\n", tn);  // t개수, pen개수, 나머지개수

	if (n / p < 1)
		printf("1 ");
	else
		printf("%d ", (int)(n / p));

	printf("%d", n % p);


	free(k);

	return 0;
}