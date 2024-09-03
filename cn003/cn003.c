//有问题的代码
#include<stdio.h>
int main()
{
    int i, j, n, x;
    for (i = 1; i < 85; i++)
    {
        if ((i % 168) == 0)
        {
            j = 168 / i;
            if (i > j && ((i + j) % 2) == 0 && ((i - j) % 2) == 0)
            {
                n = (i - j) / 2;
                x = n * n - 100;
                printf("The number is %d\n", x);
            }
        }
    }
    return 0;
}
