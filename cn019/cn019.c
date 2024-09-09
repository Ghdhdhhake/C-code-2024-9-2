//have issue
#include<stdio.h>
#include<stdlib.h>
#define N 1000
int findDivisors(int num, int **divisors)
{
	int sum = 1;
	int count = 1;
	*divisors = (int*)malloc(num * sizeof(int));
	(*divisors)[0] = 1;
	for (int j = 2; j <= num / 2; ++j)
	{
		if (num % j == 0)
		{
			sum += j;
			(*divisors)[count++] = j;
		}
	}
	return sum;
}
void main()
{
	for (int i = 2; i <= N; ++i)
	{
		int* divisors;
		int sum = findDivisors(i, &divisors);
		if (i == sum)
		{
			printf("%d = %d", i, divisors[0]);
			for (int n = 1; divisors[n] != 0; ++n)
			{
				printf(" + %d", divisors[n]);
			}
			printf("\n");
		}
		free(divisors);
	}
}