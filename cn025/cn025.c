#include<stdio.h>
void main()
{
	int i, j;
	long long sum = 0, num;
	for (i = 1; i <= 20; i++)
	{
		num = 1;
		for (j = 1; j <= i; j++)
		{
			num *= j;
		}
		sum += num;
	}
	printf("%lld", sum);
}
