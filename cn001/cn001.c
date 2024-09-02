#include<stdio.h>
void main()
{
	int count = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				if (i != j && j != k && k != i)
				{
					printf("%d%d%d\n",i,j,k);
					count++;
				}
			}
		}
	}
	printf("There are %d results in all",count);
	return 0;
}