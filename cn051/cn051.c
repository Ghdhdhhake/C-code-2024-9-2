#include<stdio.h>
void main()
{
	int a, b;
	a = 077;
	b = a & 3;
	printf("a & b(decimal) = %d\n", b);
	b &= 7;
	printf("a & b(decimal) = %d", b);

}