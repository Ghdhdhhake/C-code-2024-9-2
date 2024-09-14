#include<stdio.h>
#define N 10
#define swap(a, b){a = a + b; b = a - b; a = a - b;}

int sortnum(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return arr, n;
}


int main()
{
	int number[N];
	printf("Enter 10 numbers :\n");
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &number[i]);
	}
	sortnum(number, N);
	printf("Sort answer :\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	return 0;
}