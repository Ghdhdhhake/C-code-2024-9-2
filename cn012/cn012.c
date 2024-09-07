//output prime number(101 ~ 200)
#include<stdio.h>
void main()
{
	int i, j;
	for (i = 101; i < 201; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (i == j)
			printf("%d\n", i);
	}
}