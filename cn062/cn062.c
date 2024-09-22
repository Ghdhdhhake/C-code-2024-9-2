#include<stdio.h>
#include<stdlib.h>
#define MAX 255
int R[MAX];

void Heapify(int s, int m)
{
	int j, temp;
	temp = R[s];
	j = 2 * s;
	while (j <= m)
	{
		if (R[j] > R[j + 1] && j < m)
			j++;
		if (temp < R[j])
			break;
		R[s] = R[j];
		s = j;
		j = j * 2;
	}
	R[s] = temp;
}

void BuildHeap(int n)
{
	int i;
	for (i = n / 2; i > 0; i--)
		Heapify(i, n);
}

void Heap_Sort(int n)
{
	int i;
	BuildHeap(n);
	for (i = n; i > 1; i--)
	{
		R[0] = R[1];
		R[1] = R[i];
		R[i] = R[0];
		Heapify(1, i - 1);
	}
}
void main()
{
	int n, i;
	puts("Enter N:");
	scanf_s("%d", &n);
	if (n <= 0 || n > MAX)
	{
		puts("Error");
		exit(0);
	}
	puts("Please input element one by one :");
	for (i = 1; i <= n; i++)
		scanf_s("%d", &R[i]);
	puts("The sequence you intput is:");
	for (i = 1; i <= n; i++)
		printf("%4d", R[i]);
	Heap_Sort(n);
	puts("\nThe sequence after is:");
	for (i = n; i >= 1; i--)
		printf("%4d", R[i]);


}