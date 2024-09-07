#include<stdio.h>
void main()
{
	printf("Enter  your number:\n");
	int number, i = 2;
	scanf_s("%d", &number);
	printf("%d = 1 ", number);
	while (number > 0)
	{
		if (number == 1)
			break;
		if (number % i == 0)
		{
			printf(" * %d", i);
			number = number / i;
			i = 2;
		}
		i++;

	}
}