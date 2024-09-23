#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sortnum(int* a, int* b, int* c)
{
	if (*a > *b)
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
	printf("%d < %d < %d", *a, *b, *c);
	
}

void main()
{
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	sortnum(&a, &b, &c);
}