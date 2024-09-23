#include<stdio.h>
#define n 5
void main()
{
    int nums[n];
    int i, j = 0, temp = 0;
    for (i = 0; i < 5; i++)
    {
        scanf_s("%d", &nums[i]);
    }
    for (i = 0; i < 5; i++)
    {
        if (nums[i] != 0)
        {
            temp = nums[i];
            nums[j] = temp;
            ++j;
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", nums[i]);
    }
}
