#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
    long i = 10000000L;
    clock_t start, finish;
    double TheTimes;
    printf("��%ld�ο�ѭ����Ҫ��ʱ��Ϊ", i);
    start = clock();
    while (i--);
    finish = clock();
    TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f�롣\n", TheTimes);
}