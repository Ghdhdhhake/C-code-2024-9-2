//¿ìËÙÅÅĞò
#include<stdio.h>
#include<stdlib.h>
#define MAX 255
int R[MAX];

void sortnum(int d, int n)
{
	int i, j;
	for (i = d + 1; i <= n; i++)
	{
		if (R[i] < R[i - d])
		{
			R[0] = R[i];
			j = i - d;
			do {
				R[j + d] = R[j];
				j = j - d;
			} while (j > 0 && R[0] < R[j]);
			R[j + d] = R[0];
		}
	}
}

void shell_sort(int n)
{
	int temp = n;
	do {
		temp = temp / 3 + 1;
		sortnum(temp, n);
	} while (temp > 1);
}

void main()
{
	int n, i;
	puts("Enter n:");
	scanf_s("%d", &n);
	if (n <= 0 || n > MAX)
	{
		puts("Error!!!!!!");
		exit(0);
	}
	puts("Please input element one by one:");
	for (i = 1; i <= n; i++)
		scanf_s("%d", &R[i]);
	shell_sort(n);
	puts("Sort after:");
	for (i = 1; i <= n; i++)
		printf("%d ", R[i]);
}