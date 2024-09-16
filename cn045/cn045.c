#include<stdio.h>

void main()
{
	register int i;
	int temp = 0;
	for (i = 1; i <= 100; i++)
	{
		temp += i;
	}
	printf("sum = %d", temp);
}