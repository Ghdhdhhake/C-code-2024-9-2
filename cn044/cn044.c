#include<stdio.h>
#define swap(a, b){a = a + b; b = a - b; a = a - b;};
#define N 10
int sortnum(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return arr, n;
}
void main()
{
	int num[N] = {23, 43, 24, 34, 45, 35, 45, 65, 86, 54};
	sortnum(num, N);
	for (int i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}
}