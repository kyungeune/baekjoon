#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int t = 0, p = 0, m = 0, n = 0, sum = 0, tn = 0, cnt = 0;

	scanf("%d", &n);

	int* k = (int*)malloc((n+1) * sizeof(int));

	for (int i = 0; i < n + 1; i++) // �ʱ�ȭ
		k[i] = 0;

	for (int i = 0; sum < n;) { // ���ݱ��� �Է¹��� ���� �հ�(sum)�� n�̸��϶� ��� �Է¹ޱ�
		scanf("%d", &m); // �Է�

		if (m != 0) { // 0�� �ƴ� ��쿡�� �Է¹ޱ�
			k[cnt++] = m; // cnt = �Է¹��� ���� ����(0 ����)
		}
	}

	scanf("%d %d", &t, &p);
	
	for (int i = 0; i < cnt; i++) {
		int imsi = k[i];

		if (imsi < t)
			tn++;
		else {
			tn += (int)(imsi / t); // 0�� �ƴ� �͵��� �Է¹޾ұ� ������ 
			if (imsi % t != 0) // �������� ������ ���(=t�� ����� �ƴ� ���)
				tn++;
		}

	}

	printf("%d\n", tn);  // t����, pen����, ����������

	if (n / p < 1)
		printf("1 ");
	else
		printf("%d ", (int)(n / p));

	printf("%d", n % p);


	free(k);

	return 0;
}