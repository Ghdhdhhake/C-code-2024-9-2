#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
typedef struct
{
	int ID;
	char name[20];
	int math;
	int english;
	int c;
	int average;
}Stu;

void main()
{
	Stu st[3];
	for (int i = 0; i < 3; i++)
	{
		printf("ÇëÊäÈëÑ§ºÅ£º\n");
		scanf("%d", &st[i].ID);
		printf("ÇëÊäÈëÐÕÃû£º\n");
		scanf("%s", st[i].name);
		printf("ÇëÊäÈëmath£º\n");
		scanf("%d", &st[i].math);
		printf("ÇëÊäÈëenglish£º\n");
		scanf("%d", &st[i].english);
		printf("ÇëÊäÈëc£º\n");
		scanf("%d", &st[i].c);
		st[i].average = (st[i].math + st[i].english + st[i].c) / 3;
	}
	printf("Ñ§ºÅ\tÐÕÃû\tmath\tenglish\t\tc\taverage\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d\t%s\t%d\t%d\t\t%d\t%d\n", st[i].ID, st[i].name, st[i].math, st[i].english, st[i].c, st[i].average);
	}
	
}