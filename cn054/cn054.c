//??????????
#include<stdio.h>

void main()
{
	unsigned  a = 0, b, c, d;
	scanf_s("%o", &a);
	b = a >> 4;
	c = ~(~0<<4);
	d = b & c;
	printf("%o\n%o", a, d);
	
}