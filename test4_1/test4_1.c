#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SeqStack.h"

int main()
{
	int choice;
	SeqStack st;
	int k;
	datatype x;
	InitStack(&st);
	printf("------------------------\n");
	printf("1：入栈-----------------\n");
	printf("2：出栈-----------------\n");
	printf("3：栈顶-----------------\n");
	printf("0：退出-----------------\n");
	printf("------------------------\n");
	while (1) {
		printf("请输入你的选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("请输入入栈数据: ");
			scanf_s("%d", &x);
			k = push(&st, x);
			if (k) printf("入栈结束\n");
			else printf(" 栈为空\n");
			/*getch();*/
			break;
		case 2:
			k = pop(&st, &x);
			if (k) printf("出栈数据=%d.\n", x);
			else printf(" 栈为空\n");
			/*getch();*/
			break;
		case 3:
			k = gettop(&st, &x);
			if (k) printf("栈顶元素=%d.\n", x);
			else printf(" 栈为空\n");
			/*getch();*/
			break;
		case 0:
			exit(0); break;
		}
	}
	return 0;
	/*int num, mode;
	puts("请输入一个十进制数字以及需要转换的进制：");
	scanf("%d %d", &num, &mode);
	Convent(num, mode);*/
}
