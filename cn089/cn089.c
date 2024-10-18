#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int shift(int n)
{
	n = (n + 5) % 10;
	return n;
}
void main()
{
	int num, end;
	puts("请输入需要加密的四位数：");
	scanf("%d", &num);
	int a, b, c, d;
	a = num % 10;
	b = (num / 10) % 10;
	c = (num / 100) % 10;
	d = (num / 1000) % 10;
	end = shift(d) + shift(c) * 10 + shift(b) * 100 + shift(a) * 1000;
	printf("加密的结果是：%d", end);
	
}