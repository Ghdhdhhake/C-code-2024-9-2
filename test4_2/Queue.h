#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#define ERROR 0
#define OK 1
#define FALSE 0
#define TURE 0
#define OVERFLOW -2
#define MAXQSIZE 100				//队列最大长度

typedef int datatype;				//自定义数据元素类型为整形
typedef int Status;					//自定义函数类型为布尔

						//全局计数变量，记录入队元素个数
//在顺序存储结构上实现
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
