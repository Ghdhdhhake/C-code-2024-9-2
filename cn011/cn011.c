//rabbit numbers
#include<stdio.h>
void main()
{
	int a = 1, b = 1, c, num = 0;
	for (int i = 1; i <= 20; i++)
	{
		c = a + b;
		a = b;
		b = c;
		num += c;
		printf("%d\n", c);
	}
	printf("%d", num + 2);
}