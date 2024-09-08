#include<stdio.h>
#define swap(a, b){a = a+ b; b = a - b; a = a - b;}
void main()
{
	printf("Enter numbers N and M :\n");
	int n, m, a, b;
	scanf_s("%d %d", &n, &m);
	if (n < m)
		swap(n, m);
	a = n % m;
	b = n * m;
	while (a != 0)
	{
		n = m;
		m = a;
		a = n % m;
	}
	printf("max = %d min = %d", m, b / m);
}
//for (int i = 2; i < 10; i++)
//{
//	if (n % i == 0 && m % i == 0)
//	{
//		min = min * i;
//		m = m / i;
//		n = n / i;
//		i = 1;
//	}
//}