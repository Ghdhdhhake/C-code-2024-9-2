#include<stdio.h>

void main()
{
	int a, b;
	a = 077;
	b = a | 3;
	printf("b = %d\n", b);
	b |= 7;
	printf("b = %d", b);
}