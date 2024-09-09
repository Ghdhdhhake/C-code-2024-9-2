#include<stdio.h>
void main()
{
	int a = 1;
	for (int i = 1; i < 10; i++)
	{
		a = 2 * (a + 1);
	}
	printf("num = %d", a);
}