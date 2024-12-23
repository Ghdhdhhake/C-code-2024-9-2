#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SeqStack.h"

int main()
{
	char str[] = "({[()]()})"; // 测试字符串
	int length = sizeof(str) / sizeof(str[0]) - 1; // 计算字符串长度，减去末尾的 '\0'
	if (bracketCheck(str, length)) {
		printf("括号匹配成功的。\n");
	}
	else {
		printf("括号匹配失败。\n");
	}
	//SeqStack st;
	//int k, choice;
	//datatype x;
	//InitStack(&st);
	//convent(10, 2);


	//while (1)
	//{
	//	printf("请输入你的选择：");
	//	scanf("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:printf("入栈：");
	//		scanf("%d", &x);
	//		k = push(&st, x);
	//		if (k)printf("OK\n");
	//		else printf("空\n");
	//		break;
	//	case 2:
	//		k = pop(&st, &x);
	//		if (k)printf("出栈元素%d\n", x);
	//		else printf("空\n");
	//		break;
	//	case 3:
	//		k = gettop(&st, &x);
	//		if (k)printf("栈顶元素%d\n", x);
	//		else printf("空\n");
	//		break;
	//	default:
	//		exit(0);
	//		break;
	//	}
	//}
	return 0;
}