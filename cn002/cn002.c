#include<stdio.h>
void main()
{
	double i = 0;
	double bouns1, bouns2, bouns4, bouns6, bouns10, bouns;
	printf("Please enter your profir for the mobth:");
	scanf_s("%lf", &i);
	bouns1 = 100000 * 0.1;
	bouns2 = bouns1 + 100000 * 0.075;
	bouns4 = bouns2 + 200000 * 0.05;
	bouns6 = bouns4 + 200000 * 0.03;
	bouns10 = bouns6 + 400000 * 0.015;
	if (i < 100000)
	{
		bouns = i * 0.1;
	}
	else if (i <= 200000) 
	{
		bouns = bouns1 + (i - 100000) * 0.075;
	}
	else if (i <= 400000)
	{
		bouns = bouns2 + (i - 200000) * 0.05;
	}
	else if (i <= 600000)
	{
		bouns = bouns4 + (i - 400000) * 0.03;
	}
	else if (i <= 1000000)
	{
		bouns = bouns6 + (i - 600000) * 0.015;
	}
	else if (i > 1000000)
	{
		bouns = bouns10 + (i - 1000000) * 0.01;
	}
	printf("You can get a bousn of %lf", bouns);
}