#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int thereIs(int** s, int x, int y)
{
	if (s[x][y - 1] == 1 && y >= 1)
		return x;
	else if (s[x][y + 1] == 1 && y <= 48)
		return x;
	else if (s[x + 1][y] && x <= 48)
		return x + 1;
	else if (s[x - 1][y] && x >= 1)
		return x + 1;
	
	return 0;
}
int main(void)
{
	int n = 0, m = 0, a = 0, b = 0;

	int** save = (int**)malloc(sizeof(int*) * 50);

	for (int i = 0; i < 50; i++) {
		save[i] = (int*)malloc(sizeof(int) * 50);

		for (int j = 0; j < 50; j++)
			save[i][j] = 0;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		scanf("%d %d %d", &a, &b, &n);

		int x = 0, y = 0;
		for (int j = 0; j < n; j++) // �� �Է¹ޱ�
		{
			scanf("%d %d", &x, &y);
			save[x][y] = 1;
		}

		for (int j = 0; j < b; j++)
		{
			
			for (int z = 0; z < a; z++)
			{
				if (save[j][z] == 1) {


					int flag = 0, xz = j, yz = z; // x��ǥ y��ǥ
					
					while (flag == 0)
					{
						sum++;
						save[xz][yz] = 0;
						int hang = thereIs(save, xz, yz);
						if (hang == 0) // �ֺ��� 1�� ������, �� ����
							flag = 1;
						else { // ���� xz, yz ã��
							xz = hang;

							if (save[hang][yz - 1] == 1 && yz >= 1)
								yz = yz - 1;
							else // if (save[hang][yz + 1] == 1 && yz <= 48)
								yz = yz + 1;
						}
					}


				}
			}

		}
		printf("%d\n", sum);
	}





}