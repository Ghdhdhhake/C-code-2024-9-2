#define  _CRT_SECURE_NO_WARNINGS
//˳���
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 20
typedef int ElemType;

typedef struct Seqlist{
	ElemType data[MaxSize];
	int length;
}SeqList;


int initSeqList(SeqList* L)
{
	L->length = 0;//��ʼ��˳�����Ϊ0
	return 1;
}

int LocateSeqList(SeqList* L, int x)
{
	int i;
	for (i = 0; i < L->length && L->data[i] != x; i++);
	if (i >= L->length)
	{
		puts("˳������ڸ�Ԫ��");
	}
	return i + 1;
}

int InsertSeqList(SeqList * L, int post, int elem)
{
	int i = 0;
	if (L->length > MaxSize)
	{
		printf("˳����������޷�����");
		return 0;
	}
	else if(post < 0 || post > L->length + 1) 
	{
		printf("����λ�ô���");
		return 0;
	}
	for (int i = L->length - 1; i > post - 1; i--)
	{
		L->data[i + 1] = L->data[i];
	}

	L->data[i - 1] = elem;
	L->length++;
	return 1;
}
//ɾ��˳����е�Ԫ��
int DeletSeqList(SeqList* L, int post)
{
	if ((post < 1) || (post > L->length))
	{
		printf("����ɾ����λ�ô���");
		return 0;
	}
	for (int i = post; i < L->length; i++)//�ú�һ��Ԫ�ظ���ǰһ��Ԫ��
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return 1;
}
//��ӡ���Ա�
void DisplaySeqList(SeqList* L)
{
	int i;
	printf("˳����Ԫ����:\n");
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
}
void main()
{
	SeqList L;
	ElemType x;
	int i = 1,  post, choice = 0, elem;
	initSeqList(&L);

	InsertSeqList(&L, 1, 3);
	InsertSeqList(&L, 2, 6);
	InsertSeqList(&L, 3, 9);
	InsertSeqList(&L, 4, 0);
	InsertSeqList(&L, 5, -2);
	InsertSeqList(&L, 6, 89);
	InsertSeqList(&L, 7, 77);

	printf("**********************");
	printf("****1:����Ԫ��λ��*****");
	printf("****2:����Ԫ��*********");
	printf("****3:ɾ��Ԫ��*********");
	printf("****4:�˳�************");
	while (1)
	{
		printf("��������ţ�");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("����������Ҫ���ҵ�Ԫ��λ�ã�\n");
				scanf("%d", &post);
				i = LocateSeqList(&L, post);
				printf("����Ҫ���ҵ�Ԫ���ڵ�%dλ", i);
				i = 1;
				post = 1;
			case 2:
				printf("��������Ҫ�����Ԫ�ؼ���λ�ã�\n");
				scanf("%d %d", &elem,&post);
				InsertSeqList(&L, post, elem);
				DisplaySeqList(&L);
		}

	}

}