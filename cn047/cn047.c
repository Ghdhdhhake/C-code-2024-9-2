#include<stdio.h>
#define swap(a, b) {a = a + b; b = a - b; a = a - b;}
void main()
{
	int a = 1, b = 2;
	printf("a = %d b = %d\n", a, b);
	swap(a, b);
	printf("a = %d b = %d", a, b);
}