#include<stdio.h>
#include<math.h>
void main()
{
	int count = 0, i, sum = 0;
	for (i = 1; i <= 8; i++)
	{
		if (i == 1)
		{
			sum = 4;
			printf("when i = %d, sum = %d\n", i, sum);
			count += sum;
			sum = 0;
		}
		else if (i == 2)
		{
			sum = 4 * 7;
			printf("when i = %d, sum = %d\n", i, sum);
			count += sum;
			sum = 0;
		}
		else {
			sum = 4 * 7 * pow(8, i - 2);
			printf("when i = %d, sum = %d\n", i, sum);
			count += sum;
			sum = 0;
		}
	}
	printf("All in all sum = %d", count);
}
