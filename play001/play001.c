#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>
#include<time.h>
#define pi 3.1415926
void draw(int a, int b, int c)
{
	float x, y;
	x = a * cos(b * c * pi / 180 - pi / 2) + 300;						/*确定横坐标*/
	y = a * sin(b * c * pi / 180 - pi / 2) + 240;						/*确定纵坐标*/
	setlinestyle(PS_SOLID, 3);									/*设置线形*/
	line(300, 240, x, y);									/*绘制时针或分针或秒针*/
}
void init()												/*自定义函数初始化时钟界面*/
{
	int i, r, x1, x2, y1, y2;								/*定义变量类型为基本整型*/

	setbkcolor(BLUE);										/*设置背景颜色为蓝色*/
	cleardevice();
	setcolor(GREEN);										/*设置绘图颜色为绿色*/
	setfillcolor(RED);									/*设置填充形式为红色实填充*/
	circle(300, 240, 200);									/*以（300，240）为圆心，200为半径画圆*/
	circle(300, 240, 205);									/*以（300，240）为圆心，200为半径画圆*/
	floodfill(300, 37, GREEN);								/*对指定区域进行填充*/
	circle(300, 240, 5);									/*以（300，240）为圆心，5为半径画圆*/
	for (i = 0; i < 60; i++)
	{
		if (i % 5 == 0)
		{
			setcolor(WHITE);								/*绘图颜色为白色*/
			setfillstyle(BS_SOLID, GREEN);							/*设置填充形式为绿色实填充*/
			r = 10;										/*r赋初值为10*/
			x2 = (200 - r) * cos(i * 6 * pi / 180) + 300;				/*确定要绘制的实心圆的横坐标*/
			y2 = (200 - r) * sin(i * 6 * pi / 180) + 240;				/*确定要绘制的实行圆的纵坐标*/
			solidcircle(x2, y2, 8);							/*指定位置绘制实行圆*/
		}
		else
		{
			r = 5;										/*r赋初值为5*/
			x1 = 200 * cos(i * 6 * pi / 180) + 300;
			y1 = 200 * sin(i * 6 * pi / 180) + 240;
			x2 = (200 - r) * cos(i * 6 * pi / 180) + 300;
			y2 = (200 - r) * sin(i * 6 * pi / 180) + 240;
			setcolor(GREEN);
			line(x1, y1, x2, y2);								/*画线*/
		}
	}
}
int main()
{
	int x, y;
	int gdriver, gmode;
	unsigned char h, m, s;
	struct tm* t;
	time_t te;
	time(&te);											/*将计算机时间写入结构体t中*/
	gdriver = DETECT;
	initgraph(640, 480);							/*图形方式初始化*/
	init();												/*调用init（）函数*/
	t = localtime(&te);
	h = t->tm_hour;										/*h赋初值当前时数*/
	m = t->tm_min;										/*m赋初值当前分数*/
	s = t->tm_sec;										/*s赋初值当前秒数*/
	setlinecolor(RED);
	draw(150, h, 30);										/*画时针*/
	setlinecolor(WHITE);
	draw(170, m, 6);										/*画分针*/
	setlinecolor(YELLOW);
	draw(190, s, 6);										/*画秒针*/
	while (!_kbhit())
	{
		while (t->tm_sec == s)
			//gmtime(t);
			setcolor(RED);
		draw(190, s, 6);									/*清除前面画的秒针*/
		s = t->tm_sec;
		draw(190, s, 6);									/*画秒针*/
		if (t->tm_min != m)
		{
			setcolor(WHITE);
			draw(170, m, 6);								/*清除前面画的分针*/
			m = t->tm_min;
			draw(170, m, 6);								/*画分针*/
		} if (t->tm_hour != h)
		{
			setcolor(YELLOW);
			draw(150, h, 30);								/*清除前面画的时针*/
			h = t->tm_hour;
			draw(150, h, 30);								/*画时针*/
		}
	}
	_getch();
	closegraph();										/*退出图形界面*/
	return 0;
}

