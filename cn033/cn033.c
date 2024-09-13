#include<stdio.h>
void main()
{
	int a = 0;
	for (int j = 2; j < 1000; j++)
	{
		for (int i = 2; i < j; i++)
		{
			if ((j % i) == 0)a = 1;
		}
		if (a != 1)
			printf("%d\n", j);
		a = 0;
	}
}