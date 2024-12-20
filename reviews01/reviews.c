#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 50
typedef struct {
	int data[MAX];
	int length;
}SeqList;

void initList(SeqList* L)
{
	L->length = 0;
}

void Display(SeqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

int ListInster(SeqList* L, int post, int x)
{
	if (post < 0 || post > L->length + 1)
	{
		printf("插入位置错误");
		return 0;
	}
	if (post > MAX) return 0;
	for (int i = L->length; i >= post - 1; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[post - 1] = x;
	L->length++;
	return 1;
}

void MergeList(SeqList A, SeqList B, SeqList* C)
{
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length)
	{
		if (A.data[i] >= B.data[j])
			C->data[k++] = A.data[i++];
		else
			C->data[k++] = B.data[j++];
	}
	if (i < A.length)
		C->data[k++] = A.data[i++];
	if (j < B.length)
		C->data[k++] = B.data[j++];
	C->length = k;
}
//typedef struct {
//	int data[MAX];
//	int length;
//}SeqList;
//
//void initList(SeqList* q)
//{
//	q->length = 0;
//}
////void initElem(SeqList* q)
////{
////	int elem;
////	puts("请输入你需要输入的元素个数：");
////	scanf("%d", q->length);
////	for (int i = 0; i <= q->length- 1; i++)
////	{
////		printf("请输入第%d个元素的值：", i + 1);
////		scanf("%d", &elem);
////		q->data[i] = elem;
////		elem = 0;
////	}
////}
//void printfList(SeqList q)
//{
//	for (int i = 0; i < q.length; i++)
//	{
//		printf(" %d", q.data[i]);
//	}
//	printf("\n");
//}
//
//int ListInster(SeqList* q, int post, int elem)
//{
//	if(post < 1 || post > q->length + 1)
//	{
//		return 0;
//	}
//	if (post >= MAX)
//	{
//		return 0;
//	}
//	for(int i = q->length; i > post; i--)
//	{
//		q->data[i] = q->data[i - 1];
//	}
//	q->data[post - 1] = elem;
//	q->length++;
//	return 1;
//}
//
//
//void MergeList(SeqList a, SeqList b, SeqList* c)
//{
//	int i = 0, j = 0, k = 0;
//	while (i < a.length && j < b.length)
//	{
//		if (a.data[i] <= b.data[j])
//			c->data[k++] = a.data[i++];
//		else
//			c->data[k++] = b.data[j++];
//	}
//	while (i < a.length)
//	{
//		c->data[k++] = a.data[i++];
//	}
//	while (j < b.length)
//	{
//		c->data[k++] = b.data[j++];
//	}
//	c->length = k;
//}


void main()
{
	SeqList A, B, C;

	initList(&A);
	initList(&B);
	initList(&C);

	ListInster(&A, 1, 29);
	ListInster(&A, 2, 18);
	ListInster(&A, 3, 12);
	ListInster(&A, 4, 7);
	ListInster(&A, 5, 6);

	ListInster(&B, 1, 33);
	ListInster(&B, 2, 22);
	ListInster(&B, 3, 17);
	ListInster(&B, 4, 12);
	ListInster(&B, 5, 5);

	Display(A);
	Display(B);

	MergeList(A, B, &C);
	Display(C);
}