#pragma once
#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#define MAXSIZE 100

typedef int datatype;
// ˳��ջ�Ķ���
typedef struct sqsStack
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;
void InitStack(SeqStack* s);//ջ�ĳ�ʼ��
int push(SeqStack* s, datatype x);//��ջ����
int pop(SeqStack* s, datatype* x);//��ջ����
int gettop(SeqStack* s, datatype* x);//��ȡջ��Ԫ��
int isempty(SeqStack s);//�пղ���
void Convent(int num, int mode);//����ת��

#endif
