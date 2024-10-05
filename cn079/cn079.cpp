#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14

void fivePointedStar(int radius, double startAngle)
{
    double delta = 2 * PI / 5;
    POINT points[5]; //
    for (int i = 0; i < 5; i++)
    {
        points[i].x = (LONG)(cos(startAngle + i * delta * 2) * radius); // ����x����
        points[i].y = (LONG)(sin(startAngle + i * delta * 2) * radius); // ����y����
    }
    solidpolygon(points, 5);
}

int main(void)
{
    int width = 900;
    // �߶�Ϊ��ȵ�2/3

    int height = width / 3 * 2;
    // ������

    int grid = width / 2 / 15;
    // ��������

    initgraph(width, height);
    setbkcolor(RED);
    cleardevice();
    // ��ת�����ᣬ���������ɫΪ��ɫ

    setaspectratio(1, -1);
    setfillcolor(YELLOW);
    setpolyfillmode(WINDING);
    // �������

    setorigin(grid * 5, grid * 5);
    fivePointedStar(grid * 3, PI / 2);
    // С�����1

    setorigin(grid * 10, grid * 2);
    double startAngle = atan(3.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);
    // С�����2

    setorigin(grid * 12, grid * 4);
    startAngle = atan(1.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    // С�����3

    setorigin(grid * 12, grid * 7);
    startAngle = -atan(2.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    // С�����4

    setorigin(grid * 10, grid * 9);
    startAngle = -atan(4.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);

    getchar();
    closegraph();
    return 0;
}