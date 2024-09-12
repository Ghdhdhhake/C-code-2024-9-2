#include<stdio.h>

void main()
{
	int num, a, b, c, d;
	scanf_s("%d", &num);
	a = num % 10;
	b = (num / 10) % 10;
	c = (num / 1000) % 10;
	d = (num / 10000) % 10;
	if (a == d && c == b)
		printf("Yes");
	else
		printf("No");
}