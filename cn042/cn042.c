#include<stdio.h>

void main()
{
	int num = 1;
	
	for (int i = 0; i < 3; i++)
	{
		printf("num variable = %d\n", num);
		num++;
		{
			auto int num = 1;
			printf("Built-in modules = %d\n", num);
			num++;
		}
		
	}
}