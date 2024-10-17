#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main() //主函数 ——测试循环顺序队列各操作函数
{
	SqQueue Q;
	int i, n, a;
	datatype e, e1, e2;
	while (1)
	{
		printf(" \n******************主菜单---- 队列的基本操作****************\n\n");
		printf(" 1---循环顺序队（附设计数值的方法）\n");
		printf(" 2---循环顺序队（少用一个存储空间的方法）\n");
		printf(" 3---退出\n");
		printf("请输入选择（1-3）：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			InitSeQueue(&Q); //创建一个空的循环顺序队列
			printf("\nPlease input the length:");//请求输入循环顺序队列中元素个数
			scanf("%d", &n);
			printf("Please input the Value:\n");//请求输入循环顺序队列中各个元素
			for (i = 0; i < n; i++)
			{
				scanf("%d", &e);
				EnQueue(&Q, e);
			}
			printf("The Queue is:");
			Display(Q); //输出初始队列
			GetHead(Q, &e);
			printf("The Queue head is:%d\n", e);
			printf("Please input the insert elem:");//请求输入需要插入的新元素
			scanf("%d", &e1);
			EnQueue(&Q, e1); //入队
			printf("The Queue after EnQueue is:");
			Display(Q); //输出入队操作后的队列
			DeQueue(&Q, &e2); //出队
			printf("This is deleted:%d\n", e2);
			printf("The Queue after DeQueue is:");
			Display(Q); //输出出队操作后的队列
			printf("The length of the Queue is :%d\n", Q.num); //输出队列的长度
			printf("The Queue is empty?(Y/N) :%c\n", QueueEmpty(Q) ? 'Y' : 'N');//判断队列是否为空
				break;
		case 2:
			InitSeQueue(&Q); //创建一个空的循环顺序队列
			printf("\nPlease input the length:");//请求输入循环顺序队列中元素个数
			scanf("%d", &n);
			printf("Please input the Value:\n");//请求输入循环顺序队列中各个元素
			for (i = 0; i < n; i++)
			{
				scanf("%d", &e);
				EnQueue_1(&Q, e);
			}
			printf("The Queue is:");
			Display(Q); //输出初始队列
			GetHead_1(Q, &e);
			printf("The Queue head is:%d\n", e);
			printf("Please input the insert elem:");//请求输入需要插入的新元素
			scanf("%d", &e1);
			EnQueue_1(&Q, e1); //入队
			printf("The Queue after EnQueue is:");
			Display(Q); //输出入队操作后的队列
			DeQueue_1(&Q, &e2); //出队
			printf("This is deleted:%d\n", e2);
			printf("The Queue after DeQueue is:");
			Display(Q); //输出出队操作后的队列
			printf("The length of the Queue is :%d\n", (Q.rear - Q.qfront) %
				MAXQSIZE); //输出队列的长度
			printf("The Queue is empty?(Y/N) :%c\n", QueueEmpty_1(Q) ? 'Y' : 'N');//判断链队伍是否为空
				break;
		case 3:
			return 0;
		}
	}
} 