#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, * LinkList;

// ��������ʹ��β�巨��
void CreateList(LinkList* L, int n) {
    LinkList p, tail;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    tail = *L;
    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

// ��ȡ������Ԫ��
int GetElem(LinkList L, int i, int* e) {
    int j = 1;
    LinkList p = L->next;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return 0;
    *e = p->data;
    return 1;
}

// ����Ԫ�ص�������
int InsertList(LinkList* L, int i, int e) {
    int j = 1;
    LinkList s, p = *L;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return 0;
    s = (LinkList)malloc(sizeof(Node));
    if (!s) {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// ɾ��������Ԫ��
int DeleteList(LinkList* L, int i, int* e) {
    int j = 1;
    LinkList q, p = *L;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i) {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}

// ��ʾ����
void DisplayList(LinkList L) {
    LinkList p = L->next;
    printf("����Ԫ��Ϊ��");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//��������
void ReverseList(LinkList L)
{
    LinkList p, s;
    p = L->next;
    L->next = NULL;
    while (p) 
    {
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
    }
}
//����
//int GetNUm(LinkList L, int post, int x)
//{
//    LinkList p;
//    p = L->next;
//    int j = 1; 
//    while (p && j > post)
//    {
//        p = p->next;
//        ++j;
//    }
//    while (!p || j > post) return 0;
//    x = p->data;
//    return 1;
//}
// �ͷ�����
void FreeList(LinkList* L) {
    LinkList p, q;
    p = *L;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    *L = NULL; // ȷ��ָ���ÿ�
}

// ��������ʾ
int main() {
    LinkList L;
    int n, pos, value, elem;

    CreateList(&L, 5); // ������5�������������
    DisplayList(L);

    pos = 3;
    GetElem(L, pos, &elem);
    printf("λ��%d��Ԫ���ǣ�%d\n", pos, elem);
  
    pos = 2;
    value = 100;
    InsertList(&L, pos, value);
    printf("�ɹ���λ��%d����Ԫ��%d\n", pos, value);
    DisplayList(L);
  
    pos = 4;
    DeleteList(&L, pos, &elem);
    printf("�ɹ�ɾ��λ��%d��Ԫ��%d\n", pos, elem);
    DisplayList(L);
    printf("�������ý��Ϊ\n");
    ReverseList(L);
    DisplayList(L);
    FreeList(&L);

    return 0;
}