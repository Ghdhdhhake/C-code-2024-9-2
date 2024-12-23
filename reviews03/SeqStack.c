#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAXSIZE 100

typedef char datatype;
typedef struct SeqStack
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack* s)
{
	s->top = -1;
}

int push(SeqStack* s, datatype x)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	s->data[++s->top] = x;
	return 1;
}

int pop(SeqStack* s, datatype * x)
{
	if (s->top == - 1)
		return 0;
	*x = s->data[s->top--];
	return 1;
}

int gettop(SeqStack* s, datatype* x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top];
	return 1;
}

int isempty(SeqStack s)
{
	if (s.top == -1)
		return 1;
	return 0;
}
//括号匹配
int bracketCheck(char str[], int length) {
	SeqStack S;
	InitStack(&S); //初始化栈
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(&S, str[i]); //扫描到左括号就入栈
		}
		else {
			if (isempty(S)) { //扫描到右括号，当前栈为空，即右括号单身情况
				return 0; //匹配失败
			}
			char topElem; //用来保存弹出栈的栈顶元素
			pop(&S, &topElem); //栈顶元素出栈
			if (str[i] == ')' && topElem != '(') {
				return 0;
			}
			if (str[i] == '}' && topElem != '{') {
				return 0;
			}
			if (str[i] == ']' && topElem != '[') {
				return 0;
			}
		}
	}
	return isempty(S);
}


void convent(int num, int mode)
{
	int h;
	SeqStack s;
	printf("转化结果为：\n");
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