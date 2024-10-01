#include<stdio.h>

void main()
{
	int num[100], i, n, m, k;
	puts("Enter the number of people:");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		num[i] = i + 1;
	i = 0;
	m = 0;
	k = 0;
	while (m < n - 1)
	{
		if (num[i] != 0)
			k++;
		if (k == 3) {
			k = 0;
			num[i] = 0;
			m++;
		}
		i++;
		if (i == n)
		{
			i = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (num[i] != 0)
			printf("%d ", i+1);
	}
}