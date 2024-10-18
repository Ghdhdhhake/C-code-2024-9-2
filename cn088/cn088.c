#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Display(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("*");
	}
}
void main()
{
	int n;
	for (int i = 0; i < 7; i++)
	{
		while (1)
		{
			printf("\nÇëÊäÈëÊý×Ö£º\n");
			scanf("%d", &n);
			if (n < 50) {
				break;
			}
		}
		Display(n);
	}
}