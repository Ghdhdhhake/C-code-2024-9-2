#pragma once
#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#define MAXSIZE 100

typedef int datatype;
// 顺序栈的定义
typedef struct sqsStack
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;
void InitStack(SeqStack* s);//栈的初始化
int push(SeqStack* s, datatype x);//入栈操作
int pop(SeqStack* s, datatype* x);//出栈操作
int gettop(SeqStack* s, datatype* x);//获取栈顶元素
int isempty(SeqStack s);//判空操作
void Convent(int num, int mode);//进制转换

#endif
