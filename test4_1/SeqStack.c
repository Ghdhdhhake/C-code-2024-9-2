#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 100

typedef int datatype;
// 顺序栈的定义
typedef struct sqsStack
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;
//顺序栈的初始化
void InitStack(SeqStack* s)
{
	s->top = -1;
}
//入栈
int push(SeqStack* s, datatype x)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	s->data[++s->top] = x;
	return 1;  
}
//出栈
int pop(SeqStack* s, datatype* x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top--];
	return 1;
}
//取栈顶元素
int gettop(SeqStack* s, datatype* x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top];
	return 1;
}
//判空操作
int isempty(SeqStack s)
{
	if (s.top == -1)
		return 1;
	return 0;
}

void Convent(int num, int mode)
{
	int h;
	SeqStack s;
	printf("结果转化为：");
	InitStack(&s);
	if (num > 0)
	{
		while (num != 0)
		{
			h = num % mode;
			push(&s, h);
			num = num / mode;
		}
		while (!isempty(s))
		{
			pop(&s, &h);
			printf("%d", h);
		}
		printf("\n");
	}
}