#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strlen
//목표 : 코드 예쁘게 짜기
//더 우선되는 목표 : 결과 도출
int main(void)
{
	char s[101]; //여기에 입력
	char imsi[101]; //알파벳 중복확인용 저장하는 곳
	int i, j, z, n, count = 0, len, im = 0, pass = 0, thereIs = 0, same = 0, k = 0; //im = imsi변수측정용  thereIs : 임시배열에 있는지

	scanf("%d", &n);

	for (i = 0; i < n; i++) //n만큼
	{
		scanf("%s", s);

		len = strlen(s);

		//초기화
		pass = 0;
		same = 0; 
		thereIs = 0;
		im = 0;
		for (j = 0; j < len; j++)
			imsi[j] = '0';

		for (j = 0; j < len; j++) //단어 확인
		{
			//임시에 없으면 집어넣기
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
				//임시에 있는데 가장 최근께 아니라면 break pass해버려 
				if (s[j-1]!=s[j]) {
					pass = 1;
					break;
				}
				//				만약 가장 최근것과 동일하면 same으로 해서 계속 이어나가 그 알파벳 k에 넣어
				else {
					same = 1;
					k = s[j];
				}
			}
			else if(thereIs==1&&same==1) {
				//				same이 1인 상태에서 계속 이어지고, k랑 같으면 계속 이어나가고 k랑 달라지면 break
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