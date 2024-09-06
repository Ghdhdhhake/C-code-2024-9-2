#include<stdio.h>

void main()
{
	for (int a = 1; a <= 8; a++)
	{
		for (int b = 1; b <= 8; b++)
		{
			if ((a + b) % 2 == 0)
				printf("%c%c", 0xa8, 0x80);
			else
				printf(" ");
		}
		printf("\n");
	}
}