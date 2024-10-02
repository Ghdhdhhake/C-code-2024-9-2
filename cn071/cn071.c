//sb vs2022
#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct {
    char name[20];
    char sex[5];
    int  age;
}Stu;

int main()
{
    int i;
    Stu stu[N];
    printf("请输入5个学生的信息：姓名 性别 年龄:\n");
    for (i = 0; i < N; i++)
        scanf_s("%s %s %d", stu[i].name, stu[i].sex, &(stu[i].age));
    printf("5个学生的信息如下：\n姓名  性别  年龄\n");
    for (i = 0; i < N; i++)
        printf("%s %s %d\n", stu[i].name, stu[i].sex, stu[i].age);

    system("pause");
    return 0;
}

