#include<stdio.h>
void main()
{
	char i, j, k;
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (i != k && j != k)
					{
						if (i != 'x' && k != 'x' && k != 'z')
							printf("a-%c\tb-%c\tc-%c", i, j, k);
					}
				}
			}
		}
	}
}