#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main() //������ ��������ѭ��˳����и���������
{
	SqQueue Q;
	int i, n, a;
	datatype e, e1, e2;
	while (1)
	{
		printf(" \n******************���˵�---- ���еĻ�������****************\n\n");
		printf(" 1---ѭ��˳��ӣ��������ֵ�ķ�����\n");
		printf(" 2---ѭ��˳��ӣ�����һ���洢�ռ�ķ�����\n");
		printf(" 3---�˳�\n");
		printf("������ѡ��1-3����");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			InitSeQueue(&Q); //����һ���յ�ѭ��˳�����
			printf("\nPlease input the length:");//��������ѭ��˳�������Ԫ�ظ���
			scanf("%d", &n);
			printf("Please input the Value:\n");//��������ѭ��˳������и���Ԫ��
			for (i = 0; i < n; i++)
			{
				scanf("%d", &e);
				EnQueue(&Q, e);
			}
			printf("The Queue is:");
			Display(Q); //�����ʼ����
			GetHead(Q, &e);
			printf("The Queue head is:%d\n", e);
			printf("Please input the insert elem:");//����������Ҫ�������Ԫ��
			scanf("%d", &e1);
			EnQueue(&Q, e1); //���
			printf("The Queue after EnQueue is:");
			Display(Q); //�����Ӳ�����Ķ���
			DeQueue(&Q, &e2); //����
			printf("This is deleted:%d\n", e2);
			printf("The Queue after DeQueue is:");
			Display(Q); //������Ӳ�����Ķ���
			printf("The length of the Queue is :%d\n", Q.num); //������еĳ���
			printf("The Queue is empty?(Y/N) :%c\n", QueueEmpty(Q) ? 'Y' : 'N');//�ж϶����Ƿ�Ϊ��
				break;
		case 2:
			InitSeQueue(&Q); //����һ���յ�ѭ��˳�����
			printf("\nPlease input the length:");//��������ѭ��˳�������Ԫ�ظ���
			scanf("%d", &n);
			printf("Please input the Value:\n");//��������ѭ��˳������и���Ԫ��
			for (i = 0; i < n; i++)
			{
				scanf("%d", &e);
				EnQueue_1(&Q, e);
			}
			printf("The Queue is:");
			Display(Q); //�����ʼ����
			GetHead_1(Q, &e);
			printf("The Queue head is:%d\n", e);
			printf("Please input the insert elem:");//����������Ҫ�������Ԫ��
			scanf("%d", &e1);
			EnQueue_1(&Q, e1); //���
			printf("The Queue after EnQueue is:");
			Display(Q); //�����Ӳ�����Ķ���
			DeQueue_1(&Q, &e2); //����
			printf("This is deleted:%d\n", e2);
			printf("The Queue after DeQueue is:");
			Display(Q); //������Ӳ�����Ķ���
			printf("The length of the Queue is :%d\n", (Q.rear - Q.qfront) %
				MAXQSIZE); //������еĳ���
			printf("The Queue is empty?(Y/N) :%c\n", QueueEmpty_1(Q) ? 'Y' : 'N');//�ж��������Ƿ�Ϊ��
				break;
		case 3:
			return 0;
		}
	}
} 