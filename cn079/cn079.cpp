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
        points[i].x = (LONG)(cos(startAngle + i * delta * 2) * radius); // 计算x坐标
        points[i].y = (LONG)(sin(startAngle + i * delta * 2) * radius); // 计算y坐标
    }
    solidpolygon(points, 5);
}

int main(void)
{
    int width = 900;
    // 高度为宽度的2/3

    int height = width / 3 * 2;
    // 网格宽度

    int grid = width / 2 / 15;
    // 创建窗体

    initgraph(width, height);
    setbkcolor(RED);
    cleardevice();
    // 翻转坐标轴，设置填充颜色为黄色

    setaspectratio(1, -1);
    setfillcolor(YELLOW);
    setpolyfillmode(WINDING);
    // 大五角星

    setorigin(grid * 5, grid * 5);
    fivePointedStar(grid * 3, PI / 2);
    // 小五角星1

    setorigin(grid * 10, grid * 2);
    double startAngle = atan(3.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);
    // 小五角星2

    setorigin(grid * 12, grid * 4);
    startAngle = atan(1.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    // 小五角星3

    setorigin(grid * 12, grid * 7);
    startAngle = -atan(2.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    // 小五角星4

    setorigin(grid * 10, grid * 9);
    startAngle = -atan(4.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);

    getchar();
    closegraph();
    return 0;
}