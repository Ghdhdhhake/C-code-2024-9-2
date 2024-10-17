#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 0
#define OVERFLOW -2
#define MAXQSIZE 100				//队列最大长度

typedef int datatype;				//自定义数据元素类型为整形
typedef int Status;					//自定义函数类型为布尔

int flag = 0;						//全局标志量， 标志入、出对操作
int num = 0;						//全局计数变量，记录入队元素个数
//在顺序存储结构上实现
typedef struct {
	datatype data[MAXQSIZE];
	int qfront;
	int rear;
	int num;
}SqQueue;

//创建一个空的循环队列
Status InitSeQueue(SqQueue *Q)
{
	Q->qfront = Q->rear = -1;
	Q->num = 0;
	return OK;
}
//循环队列为空返回真值，否则返回假值
Status QueueEmpty(SqQueue Q)
{
	if (Q.num == 0)
		return TURE;
	else
		return FALSE;
}
//循环队列为空返回真值，否则返回假值
Status QueueEmpty_1(SqQueue Q)
{
	if (Q.qfront == Q.rear)
		return TURE;
	else
		return FALSE;
}
//读取循环列表的队首元素，用e保存
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
//读取循环列表的队首元素，用e保存
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
//在循环队列中插入元素e，使其成为新的队尾元素
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
//在循环队列中插入元素e，使其成为新的队尾元素
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
//删除队首元素值，并用e返回其值
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
//删除队首元素值，并用e返回其值
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
//输出循环队列中每个元素的值
void Display(SqQueue Q)
{
	int i;
	for (i = Q.qfront + 1; i <= Q.rear; i = (i + 1) % MAXQSIZE)
		printf("%4d", Q.data[i]);
	printf("\n");
}