//nesting
#include<stdio.h>
void main()
{
	printf("Enter your score: \n");
	int score;
	scanf_s("%d", &score);
	score >= 90 ? printf("A") : (score > 60 ? printf("B") : printf("c"));
}