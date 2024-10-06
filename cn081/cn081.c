#include<stdio.h>
//Profiteering aesthetics

void main()
{
	int i, temp = 0;
	for (i = 0; i < 100; i++)
	{
		if (809 * i == 800 * i + 9 * i && 809 * i < 10000 && 8 * i < 100 && 9 * i < 1000)
			temp = i;
		else
			break;
	}
	printf("The num = %d, end = %d", temp, temp * 809);
}