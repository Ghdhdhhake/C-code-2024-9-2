#include<stdio.h>
void  main()
{
	int num[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
	int temp2 = 0, temp1 = 0, number;
	printf("Enter your number :\n");
	scanf_s("%d", &number);
	if (number > num[9])
		num[10] = number;
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (num[i] > number)
			{
				temp1 = num[i];
				num[i] = number;
				for (int j = i + 1; j < 11; j++)
				{
					temp2 = num[j];
					num[j] = temp1;
					temp1 = temp2;
				}
				break;
			}
		}
	}

	printf("Consequence: \n");
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", num[i]);
	}
}