#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 0
#define OVERFLOW -2
#define MAXQSIZE 100				//������󳤶�

typedef int datatype;				//�Զ�������Ԫ������Ϊ����
typedef int Status;					//�Զ��庯������Ϊ����

int flag = 0;						//ȫ�ֱ�־���� ��־�롢���Բ���
int num = 0;						//ȫ�ּ�����������¼���Ԫ�ظ���
//��˳��洢�ṹ��ʵ��
typedef struct {
	datatype data[MAXQSIZE];
	int qfront;
	int rear;
	int num;
}SqQueue;

//����һ���յ�ѭ������
Status InitSeQueue(SqQueue *Q)
{
	Q->qfront = Q->rear = -1;
	Q->num = 0;
	return OK;
}
//ѭ������Ϊ�շ�����ֵ�����򷵻ؼ�ֵ
Status QueueEmpty(SqQueue Q)
{
	if (Q.num == 0)
		return TURE;
	else
		return FALSE;
}
//ѭ������Ϊ�շ�����ֵ�����򷵻ؼ�ֵ
Status QueueEmpty_1(SqQueue Q)
{
	if (Q.qfront == Q.rear)
		return TURE;
	else
		return FALSE;
}
//��ȡѭ���б�Ķ���Ԫ�أ���e����
Status GetHead(SqQueue Q, datatype* e)
{
	if (Q.num == 0)
	{
		printf("NULL\n");
		return ERROR;
	}
	*e = Q.data[Q.qfront + 1];
	return OK;
}
//��ȡѭ���б�Ķ���Ԫ�أ���e����
Status GetHead_1(SqQueue Q, datatype* e)
{
	if (Q.qfront == Q.rear)
	{
		printf("NULL\n");
		return ERROR;
	}
	*e = Q.data[Q.qfront + 1];
	return OK;
}
//��ѭ�������в���Ԫ��e��ʹ���Ϊ�µĶ�βԪ��
Status EnQueue(SqQueue* Q, datatype e)
{
	if (Q->num == MAXQSIZE)
	{
		printf("OVERFLOW\n");
		return ERROR;
	}
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	Q->data[Q->rear] = e;
	Q->num++;
	return OK;
}
//��ѭ�������в���Ԫ��e��ʹ���Ϊ�µĶ�βԪ��
Status EnQueue_1(SqQueue* Q, datatype e)
{
	if (Q->qfront == (Q->rear + 1)%MAXQSIZE)
	{
		printf("OVERFLOW\n");
		return ERROR;
	}
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	Q->data[Q->rear] = e;
	return OK;
}
//ɾ������Ԫ��ֵ������e������ֵ
Status DeQueue(SqQueue* Q, datatype *e)
{
	if (Q->num == 0)
	{
		printf("EMPTY\n");
		return ERROR;
	}
	Q->qfront = (Q->qfront + 1) % MAXQSIZE;
	*e = Q->data[Q->qfront];
	Q->num--;
	return OK;
}
//ɾ������Ԫ��ֵ������e������ֵ
Status DeQueue_1(SqQueue* Q, datatype* e)
{
	if (Q->qfront == Q->rear)
	{
		printf("EMPTY\n");
		return ERROR;
	}
	Q->qfront = (Q->qfront + 1) % MAXQSIZE;
	*e = Q->data[Q->qfront];
	return OK;
}
//���ѭ��������ÿ��Ԫ�ص�ֵ
void Display(SqQueue Q)
{
	int i;
	for (i = Q.qfront + 1; i <= Q.rear; i = (i + 1) % MAXQSIZE)
		printf("%4d", Q.data[i]);
	printf("\n");
}