#define  _CRT_SECURE_NO_WARNINGS//����ʱ��
#include<stdio.h>
#include<time.h>
void main()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("��ǰ����ʱ��Ϊ: %s", asctime(timeinfo));
}