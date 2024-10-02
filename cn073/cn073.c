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
        printf("请输入第%d个元素的值:", i);
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

    printf("刚刚建立的各个链表元素的值为：\n");
    printf(Head);

    printf("\n反向输出的链表元素的值为：\n");
    printReverse(Head);   

    printf("\n\n");
    system("pause");
    return 0;
}
