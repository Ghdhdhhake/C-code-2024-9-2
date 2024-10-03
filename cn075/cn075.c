#include<stdio.h>
void reverse(int n)
{
	int m = 0;
	while (n > 0)
	{
		m = m * 10 + n % 10;
		n = n / 10;
	}
	printf("%d", m);
}
void main()
{
	puts("Enter a number: ");
	int num = 0;
	scanf_s("%d", &num);
	reverse(num);
}