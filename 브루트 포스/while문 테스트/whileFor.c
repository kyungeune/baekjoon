#include <stdio.h>
int main(void)
{
	int x = 0;
	//while¹®
	while (x < 1)
	{
		x++;
		printf("¾È³ç!\n");
		printf("¾ßÈ£\n");
	}

	//for¹®
	for (int i = 0; i < 1; i++)
	{
		printf("¾È³ç!\n");
		i++;
		printf("¾ßÈ£\n");
	}
}