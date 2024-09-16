#include<stdio.h>
#define LAG >
#define SMA <
#define EQ  ==
void main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (a LAG b)
		printf("a > b");
	else if (a SMA b)
		printf("a < b");
	else if (a EQ b)
		printf("a = b");
	else
		printf("Error");
}