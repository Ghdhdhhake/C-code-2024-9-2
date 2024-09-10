#include<stdio.h>
void main()
{
	int num = 1, sum = 0;
	for (int i = 1; i <= 22; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			num = num * j;
		}
		sum += num;
	}
	printf("sum = %d", sum);
}