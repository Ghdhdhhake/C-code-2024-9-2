//option sort
#include<stdio.h>
#define swap(a, b){a = a + b; b = a - b; a = a - b;}
void sortnum(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minNumIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				minNumIndex = j;
		}
		if (minNumIndex != i)
			swap(arr[i], arr[minNumIndex]);
	}
}
void main()
{
	int arr[] = {23, 34, 23, 34, 56, 34, 23, 45, 56, 34, 45, 67, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	sortnum(arr, n);
	for (int j = 0; j < n; j++)
	{
		printf("%d ", arr[j]);
	}
}