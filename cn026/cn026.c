#include<stdio.h>

int def(int x)
{
	if (x > 1)
		return x * def(x - 1);
	else
		return 1;
}

void main()
{
	for (int i = 0; i < 7; i++)
	{
		printf("%d! = %d\n",  i, def(i));
	}
}