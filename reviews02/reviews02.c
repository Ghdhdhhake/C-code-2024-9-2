#define  _CRT_SECURE_NO_WARNINGS
//顺序表
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
	L->length = 0;//初始化顺序表，表长为0
	return 1;
}

int LocateSeqList(SeqList* L, int x)
{
	int i;
	for (i = 0; i < L->length && L->data[i] != x; i++);
	if (i >= L->length)
	{
		puts("顺序表不存在该元素");
	}
	return i + 1;
}

int InsertSeqList(SeqList * L, int post, int elem)
{
	int i = 0;
	if (L->length > MaxSize)
	{
		printf("顺序表已满，无法插入");
		return 0;
	}
	else if(post < 0 || post > L->length + 1) 
	{
		printf("插入位置错误");
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
//删除顺序表中的元素
int DeletSeqList(SeqList* L, int post)
{
	if ((post < 1) || (post > L->length))
	{
		printf("输入删除的位置错误！");
		return 0;
	}
	for (int i = post; i < L->length; i++)//用后一个元素覆盖前一个元素
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return 1;
}
//打印线性表
void DisplaySeqList(SeqList* L)
{
	int i;
	printf("顺序表的元素有:\n");
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
	printf("****1:查找元素位置*****");
	printf("****2:插入元素*********");
	printf("****3:删除元素*********");
	printf("****4:退出************");
	while (1)
	{
		printf("请输入序号：");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("请输入你需要查找的元素位置：\n");
				scanf("%d", &post);
				i = LocateSeqList(&L, post);
				printf("你需要查找的元素在第%d位", i);
				i = 1;
				post = 1;
			case 2:
				printf("请输入你要插入的元素及其位置：\n");
				scanf("%d %d", &elem,&post);
				InsertSeqList(&L, post, elem);
				DisplaySeqList(&L);
		}

	}

}