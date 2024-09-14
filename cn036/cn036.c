#include<stdio.h>

void main()
{
	int a = 0;
	for (int i = 2; i < 100; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)a = 1;
		}
		if (a != 1) 
		{
			printf("%d\n", i);
		}
		a = 0;
	}
}