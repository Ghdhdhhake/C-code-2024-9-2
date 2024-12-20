#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int length;
    int capacity;
} SeqList;

void initList(SeqList* list, int capacity);//初始化
void printList(SeqList* list);//打印
void insertLinear(SeqList* list, int x);//查找法插入
void insertBinary(SeqList* list, int x);//二分法插入
//初始化顺序表
void initList(SeqList* list, int capacity) 
{
    list->data = (int*)malloc(capacity * sizeof(int));
    list->length = 0;
    list->capacity = capacity;
}
//打印顺序表
void printList(SeqList* list) 
{
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void insertLinear(SeqList* list, int x) {
    if (list->length >= list->capacity) {
        printf("顺序表已满，无法插入。\n");
        return;
    }
    int i;
    for (i = list->length - 1; (i >= 0) && (list->data[i] > x); i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[i + 1] = x;
    list->length++;
}

//二分法插入
void insertBinary(SeqList* list, int x) 
{
    if (list->length >= list->capacity) {
        printf("顺序表已满，无法插入。\n");
        return;
    }

    int left = 0, right = list->length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (list->data[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    for (int i = list->length - 1; i >= left; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[left] = x;
    list->length++;
}


int main()
{
    SeqList list;
    initList(&list, 10);

    // 插入初始元素
    list.data[0] = 1;
    list.data[1] = 3;
    list.data[2] = 6;
    list.data[3] = 9;
    list.length = 4;

    printf("原始序列: ");
    printList(&list);

    int x = 5;
    printf("插入的数字为5\n");
    insertLinear(&list, x);
    printf("线性查找插入: ");
    printList(&list);

    int y =6;
    printf("插入的数字为6\n");
    insertBinary(&list, y);
    printf("二分法插入: ");
    printList(&list);

    free(list.data);
    return 0;
}
