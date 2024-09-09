//End
#include<stdio.h>

void main()
{
	double high = 100, s = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i < 1)
			s += high;
		else
			s += (2 * high);
		high = high / 2;
		if (i == 9)
			printf("High` = %lf\n", high);
	}
	printf("s = %lf", s);
}