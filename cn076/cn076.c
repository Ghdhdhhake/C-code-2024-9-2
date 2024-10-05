#include<stdio.h>

double onum(int a)
{
	double tp1 = 0, tp2 = 0;
	for (int i = 1; i <= a; i += 2)
	{
		tp1 = (double)1 / i;
		tp2 += tp1;
	}
	return tp2;
}
double oonum(int a)
{
	double tp1 = 0, tp2 = 0;
	for (int i = 2; i <= a; i += 2)
	{
		tp1 = (double)1 / i;
		tp2 += tp1;
	}
	return tp2;
}
void main()
{
	int num;
	double temp = 0;
	puts("Please enter a number:");
	scanf_s("%d", &num);
	double (*p)(int) = NULL;
	p = onum;
	double (*q)(int) = NULL;
	q = oonum;
	if (num % 2 == 0)
		temp = q(num);
	else
		temp = p(num);
	printf("The end = %lf", temp);
}
