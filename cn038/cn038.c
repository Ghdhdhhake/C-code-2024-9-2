#include<stdio.h>

int main()
{
	int num[3][3], sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%d", &num[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j || i == 0 && j == 2 || i == 2 && j == 0)
				sum += num[i][j];
		}
	}
	printf("num = %d", sum);
	return 0;
}