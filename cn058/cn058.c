#include<stdio.h>
#include<stdlib.h>
#define MAX 255
int R[MAX];

void sortnum(int n)
{
	int i, j;
	for (i = 2; i < n; i++) 
	{
		if (R[i] < R[i - 1])
		{
			R[0] = R[i];
			j = i - 1;
			do {
				R[j + 1] = R[j];
				j--;
			} while (R[0] < R[j]);
			R[j + 1] = R[0];
		}
	}
}

void main()
{
	int i, n;
	puts("Please input total element number of the sequence:");
	scanf_s("%d",  &n);
	
	if (n <= 0 || n > MAX)
	{
		printf("n must more than 0 and less than %d", MAX);
		exit(0);
	}
	puts("Please input the elements one by one:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &R[i]);
	}
	puts("The sequence you input is :");
	for (i = 0; i < n; i++)
			printf("%d ", R[i]);
	sortnum(n);
	puts("\nThe squence after sortnum() is");
	for (i = 0; i < n; i++)
		printf("%d ", R[i]);
}