#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	double sum = 0, count = 0;
	char x[51];
	char y[4];
	char z[3];

	for (i = 0; i < 20; i++)
	{
		scanf("%s %s %s", x,y,z);

		double zz = 0;
		if (strcmp(z, "A+")==0)
			zz = 4.5;
		else if (strcmp(z, "A0")==0)
			zz = 4.0;
		else if (strcmp(z, "B+") == 0)
			zz = 3.5;
		else if (strcmp(z, "B0") == 0)
			zz = 3.0;
		else if (strcmp(z, "C+") == 0)
			zz = 2.5;
		else if (strcmp(z, "C0") == 0)
			zz = 2.0;
		else if (strcmp(z, "D+") == 0)
			zz = 1.5;
		else if (strcmp(z, "D0") == 0)
			zz = 1.0;
		else if (strcmp(z, "F") == 0)
			zz = 0.0;
		else if (strcmp(z, "P") == 0) {
			continue;
		}

		count += y[0] - 48;
		sum += zz * (y[0] - 48);
	}

	printf("%lf", sum / count);
}