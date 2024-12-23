#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#define MAXSIZE 100

typedef char datatype;
typedef struct SeqStack
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack* s);
int push(SeqStack* s, datatype x);
int pop(SeqStack* s, datatype* x);
int gettop(SeqStack* s, datatype* x);
int isempty(SeqStack s);
void convent(int num, int mode);
int bracketCheck(char str[], int length);

#endif
