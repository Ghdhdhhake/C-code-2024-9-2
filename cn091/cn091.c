#define  _CRT_SECURE_NO_WARNINGS//本地时间
#include<stdio.h>
#include<time.h>
void main()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("当前本地时间为: %s", asctime(timeinfo));
}