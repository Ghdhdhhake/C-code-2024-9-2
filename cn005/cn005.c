#include<stdio.h>
#define swap(a,b) { a = a + b; b = a - b; a = a - b;}
void main()
{
	printf("Please enter three number:");
	int number[3];
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &number[i]);
	}
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 0; j <= 2 - i; j++)
		{
			if (number[j] > number[j + 1])
			{
				swap(number[j], number[j + 1]);
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", number[i]);
	}
}