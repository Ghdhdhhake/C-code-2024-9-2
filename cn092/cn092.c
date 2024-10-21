#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
void main()
{
    time_t start, end;
    int i;
    start = time(NULL);
    for (i = 0; i < 100000; i++)
    {
        printf("\n");  // 返回两个time_t型变量之间的时间间隔
    }
    end = time(NULL);

    // 输出执行时间
    printf("时间间隔为 %6.3f\n", difftime(end, start));
}