#include<stdio.h>

void main()
{
	int year = 0, month = 0, day = 0, number = 0, num = 0;
	int month_number[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	printf("please enter Year Month Day:\n");
	scanf_s("%d %d %d", &year, &month, &day);
	if(year % 4 ==0)
	{
		for (int i = 0; i < (month - 1); i++)
		{
			num += month_number[i];
		}
		number = num + day;
		if (month > 2)
			number++;
		printf("It is the %dth day of %d.", number, year);
	}
	else {
		for (int i = 0; i < (month - 1); i++)
		{
			num += month_number[i];
		}
		number = num + day;
		printf("It is the %dth day of %d.", number, year);
	
	}
}