#include<stdio.h>
void main()
{
	printf("       ^_^");
	for (int i = 9; i >= 1; i--)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i <= j)
				printf("%c%c", 0xa8, 0x80);
			else
				printf(" ");
		}
		printf("\n");
	}
}