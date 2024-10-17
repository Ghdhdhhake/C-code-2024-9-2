#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 0
#define OVERFLOW -2
#define MAXQSIZE 100				//������󳤶�

typedef int datatype;				//�Զ�������Ԫ������Ϊ����
typedef int Status;					//�Զ��庯������Ϊ����

						//ȫ�ּ�����������¼���Ԫ�ظ���
//��˳��洢�ṹ��ʵ��
typedef struct {
	datatype data[MAXQSIZE];
	int qfront;
	int rear;
	int num;
}SqQueue;
Status InitSeQueue(SqQueue* Q);
Status QueueEmpty(SqQueue Q);
Status QueueEmpty_1(SqQueue Q);
Status GetHead(SqQueue Q, datatype* e);
Status GetHead_1(SqQueue Q, datatype* e);
Status EnQueue(SqQueue* Q, datatype e);
Status EnQueue_1(SqQueue* Q, datatype e);
Status DeQueue(SqQueue* Q, datatype* e);
Status DeQueue_1(SqQueue* Q, datatype* e);
void Display(SqQueue Q);

#endif
