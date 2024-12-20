#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 100 // 假设最大容量为100


typedef struct {
    int data[MAX_SIZE]; // 存储数据元素的数组
    int length;         // 当前顺序表的长度
} SeqList;

// 线性查找插入
void insertByLinear(SeqList* list, int x) {
    int i = list->length - 1;
    while (i >= 0 && list->data[i] > x) {
        list->data[i + 1] = list->data[i];
        i--;
    }
    list->data[i + 1] = x;
    list->length++;
}

// 二分查找插入
void insertByBinary(SeqList* list, int x) {
    if (list->length == 0 || x <= list->data[0]) {
        for (int i = list->length; i > 0; --i) {
            list->data[i] = list->data[i - 1];
        }
        list->data[0] = x;
        list->length++;
        return;
    }
    else if (x >= list->data[list->length - 1]) {
        list->data[list->length] = x;
        list->length++;
        return;
    }

    int low = 0, high = list->length - 1, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= list->data[mid]) high = mid;
        else low = mid + 1;
    }

    for (int i = list->length; i > low; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[low] = x;
    list->length++;
}

// 打印顺序表内容
void printSeqList(SeqList* list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    SeqList list = { {2, 4, 5, 7, 9}, 5 }; // 初始化顺序表，包含5个元素
    int x = 3; 
    printf("插入的数字为 3");
    printf("插入前序列: ");
    printSeqList(&list);

    // 线性查找表插入
    insertByLinear(&list, x); 

    printf("线性表查找插入后序列: ");
    printSeqList(&list);

    // 二分查找插入
    SeqList list2 = { {2, 4, 5, 2, 6}, 5 };
    printf("插入前序列: ");
    printSeqList(&list2);
    insertByBinary(&list2, x);
    printf("二分法插入后序列: ");
    printSeqList(&list2);

    return 0;
}