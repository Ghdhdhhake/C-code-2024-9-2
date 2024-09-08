#include<stdio.h>
#include<math.h>
void main()
{
	int a, b, c, s = 0; 
	printf("Please enter digit and number:\n");
	scanf_s("%d %d", &a, &b);
	c = a;
	while (b != 0)
	{
		s += c;
		a = a * 10;
		c += a;
		b--;
	}
	printf("a + aa + aaa + ... = %d", s);
}