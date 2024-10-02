#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct LNode {
    int          data;
    struct LNode* next;
}LNode, * LinkList;

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
        printf("�������%d��Ԫ�ص�ֵ:", i);
        scanf_s("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L->next;
}
void print(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void printReverse(LinkList h)
{
    if (h == NULL) return;
    printReverse(h->next);
    printf("%d ", h->data);
}

int main()
{
    LinkList Head = NULL;
    int n;

    scanf_s("%d", &n);
    Head = CreateList(n);

    printf("�ոս����ĸ�������Ԫ�ص�ֵΪ��\n");
    printf(Head);

    printf("\n�������������Ԫ�ص�ֵΪ��\n");
    printReverse(Head);   

    printf("\n\n");
    system("pause");
    return 0;
}
