#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct LNode {
    int          data;
    struct LNode* next;
}LNode, * LinkList;

LinkList CreateList(int n);
void DisplpayLink(LinkList h);
int main()
{
    LinkList Linked1 = NULL;
    LinkList Linked2 = NULL;
    int n, m;
    puts("Please enter n = :");
    scanf_s("%d", &n);
    Linked1 = CreateList(n); 
    puts("Please enter m = :");
    scanf_s("%d", &m);
    Linked2 = CreateList(m);
    printf("Display Linked1：\n");
    DisplpayLink(Linked1);
    printf("\n");
    printf("Display Linked2：\n");
    DisplpayLink(Linked2);
    printf("\n");


    LinkList temp = Linked1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = Linked2->next;

    printf("After merge:");
    DisplpayLink(Linked1);

    printf("\n\n");
    system("pause");
    return 0;
}
LinkList CreateList(int n)
{
    LinkList L, p, q;
    int i;
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)return 0;
    L->next = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        printf("请输入第%d个元素的值:", i);
        scanf_s("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L;
}
void DisplpayLink(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}