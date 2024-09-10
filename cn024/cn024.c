#include<stdio.h>

void main()
{
	double a = 1, b = 2, c = 0, sum = 0;
	for (int i = 0; i < 20; i++)
	{
		sum += b / a;
		c = a;
		a = b;
		b = c + b;
	}
	printf("%.6lf", sum);
}