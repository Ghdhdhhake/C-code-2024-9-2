#include<stdio.h>
#define swap(a, b) {a = a + b; b = a - b; a = a - b;}
void main()
{
    printf("Please enter Numbers:");
    int number[8];
    for (int i = 0; i < 8; i++)
    {
        scanf_s("%d", &number[i]);
    }
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 0; j <= 6 - i; j++)
        {
            if (number[j] > number[j + 1])
                swap(number[j], number[j + 1]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", number[i]);
    }
}