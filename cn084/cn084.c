#include<stdio.h>
#include<math.h>
int IsPrime(int n)
{
    int i;
    if (n == 1)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void divide_even(int even, int* a, int* b)
{
    int i;
    for (i = 2; i < even; i++)
    {
        if (IsPrime(i) && IsPrime(even - i))
            break;
    }
    *a = i;
    *b = even - i;
}

int main(void)
{
    int n, a, b;
    printf("请输入一个偶数:\n");
    scanf_s("%d", &n);
    divide_even(n, &a, &b);
    printf("偶数%d可以分解成%d和%d两个素数的和", n, a, b);
}