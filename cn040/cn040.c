#include<stdio.h>
#define N 10
void main()
{
	int num[N] = {0}, temp = 0;
	printf("Enter:\n");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &num[i]);
	}
	for (int i = 0; i < (N / 2); i++)
	{
		temp = num[i];
		num[i] = num[9 - i];
		num[9 - i] = temp;
	}
	printf("Consequence :\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}
}