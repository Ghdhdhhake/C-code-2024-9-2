#include<stdio.h>
#define TURE 1
#define FALSE 0
#define SQ(x) (x) * (x)
void main()
{
	int num = 1, number;
	printf("if number < 50 will stop\n");
	while (num)
	{
		printf("Enter number: \n");
		scanf_s("%d", &number);
		printf("The number's square is %d\n", SQ(number));
		if (number >= 50)
			num = TURE;
		else
			num = FALSE;
	}
}