#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int xMin, xMax, yMin, yMax, n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (i == 0) //ÃÊ±âÈ­
		{
			xMin = x;
			xMax = x;
			yMin = y;
			yMax = y;
		}
		else
		{
			if (x < xMin) {
				xMin = x;
			}
			else if (x > xMax) {
				xMax = x;
			}
			if (y < yMin) {
				yMin = y;
			}
			else if (y > yMax) {
				yMax = y;
			}
		}
	}

	printf("%d", (xMax - xMin) * (yMax - yMin));
}