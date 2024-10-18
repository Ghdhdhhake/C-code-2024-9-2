#include<stdio.h>//结构体传值
struct student
{
	int x;
	char y;
}a;
void main()
{
	a.x = 3;
	a.y = 'A';
	f(a);
	printf("%d %c", a.x, a.y);
}
f(struct student b)
{
	b.x = 20;
	b.y = 'a';
}