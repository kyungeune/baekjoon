#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strlen
//��ǥ : �ڵ� ���ڰ� ¥��
//�� �켱�Ǵ� ��ǥ : ��� ����
int main(void)
{
	char s[101]; //���⿡ �Է�
	char imsi[101]; //���ĺ� �ߺ�Ȯ�ο� �����ϴ� ��
	int i, j, z, n, count = 0, len, im = 0, pass = 0, thereIs = 0, same = 0, k = 0; //im = imsi����������  thereIs : �ӽù迭�� �ִ���

	scanf("%d", &n);

	for (i = 0; i < n; i++) //n��ŭ
	{
		scanf("%s", s);

		len = strlen(s);

		//�ʱ�ȭ
		pass = 0;
		same = 0; 
		thereIs = 0;
		im = 0;
		for (j = 0; j < len; j++)
			imsi[j] = '0';

		for (j = 0; j < len; j++) //�ܾ� Ȯ��
		{
			//�ӽÿ� ������ ����ֱ�
			for (z = 0; z < im; z++) {
				if (s[j] == imsi[z]) {
					thereIs = 1;
					break;
				}
				else {
					thereIs = 0;
				}
			}

			if (thereIs == 0) {
				imsi[im++] = s[j];
				same = 0;
			}

			if (thereIs==1&&same==0) {
				//�ӽÿ� �ִµ� ���� �ֱٲ� �ƴ϶�� break pass�ع��� 
				if (s[j-1]!=s[j]) {
					pass = 1;
					break;
				}
				//				���� ���� �ֱٰͰ� �����ϸ� same���� �ؼ� ��� �̾�� �� ���ĺ� k�� �־�
				else {
					same = 1;
					k = s[j];
				}
			}
			else if(thereIs==1&&same==1) {
				//				same�� 1�� ���¿��� ��� �̾�����, k�� ������ ��� �̾���� k�� �޶����� break
				if (k == s[j])
					continue;
				else {
					pass = 1;
					break;
				}
			}

		}

		if (pass == 0)
			count++;


	}
	printf("%d\n", count);
}