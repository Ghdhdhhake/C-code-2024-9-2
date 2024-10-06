#include<stdio.h>

void main()
{
	int n = 0;
	int cout, i;
	int found = 0;
	while (!found)
	{
		n += 1;
		cout = n;
		for (i = 0; i < 5; i++)
		{
			if ((cout - 1) % 5 == 0)
			{
				cout = (cout - 1) / 5 * 4;
			}
			else
				break;
		}
		if (i == 5)
			found = 1;
	}
	printf("The answer = %d", n);

}