#include<stdio.h>
#define swap(a,b) { a = a + b; b = a - b; a = a - b;}

void main()
{
	printf("Please enter three number:");
	int x, y, z;
	scanf_s("%d %d %d", &x, &y, &z);
	if (x > y)
		swap(x, y);
	if (x > z)
		swap(x, z);
	if (y > z)
		swap(y, z);
	printf("%d < %d < %d", x, y, z);
}