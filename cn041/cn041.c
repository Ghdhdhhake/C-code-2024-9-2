#include<stdio.h>

void foo()
{
	static int num = 0;
	num++;
	printf("num = %d\n", num);
}
void main()
{
	foo();
	foo();
	foo();
}