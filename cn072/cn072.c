#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct LNode {
	int data;
	struct LNode* next;

}LNode, *Linklist;
Linklist creatlist(int n)
{
	Linklist l, p, q;
	int i;
	l = (LNode*)malloc(sizeof(LNode));
	if (!l) return 0;
	l->next = NULL;
	q = l;
	for (i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(LNode));
		printf("Please enter number%d : ", i + 1);
		scanf_s("%d", &(p->data));
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return l;
}
void printlist(Linklist h)
{
	Linklist p = h->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void main()
{
	Linklist Head = NULL;
	int n;
	scanf_s("%d", &n);
	Head = creatlist(n);

	printf("Display linklist:\n");
	printlist(Head);
}