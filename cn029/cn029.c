#include<stdio.h>

void main()
{
	int number;
	int num, j, num2 = 0;
	scanf_s("%d", &number);
	num = number;
	for (int i = 1; i < 6; i++)
	{
		if (number < 10) 
		{
			printf("%d\n", i);
			j = i;
			break;
		}
		number = number / 10;
	}
	while (num != 0)
	{
		num2 = num2 * 10 + num % 10;
		num /= 10;
	}
	printf("%d", num2);
}