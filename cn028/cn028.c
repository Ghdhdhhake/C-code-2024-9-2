#include<stdio.h>
int x;
int age(x)
{
	int c;
	if (x == 1)
		c = 10;
	else
		c = age(x - 1) + 2;	
	return (c);
}
void main()
{
	printf("The old man is %d years old.", age(5));
}