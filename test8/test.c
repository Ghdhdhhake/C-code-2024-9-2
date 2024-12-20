#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 100 // �����������Ϊ100


typedef struct {
    int data[MAX_SIZE]; // �洢����Ԫ�ص�����
    int length;         // ��ǰ˳���ĳ���
} SeqList;

// ���Բ��Ҳ���
void insertByLinear(SeqList* list, int x) {
    int i = list->length - 1;
    while (i >= 0 && list->data[i] > x) {
        list->data[i + 1] = list->data[i];
        i--;
    }
    list->data[i + 1] = x;
    list->length++;
}

// ���ֲ��Ҳ���
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

// ��ӡ˳�������
void printSeqList(SeqList* list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// ������
int main() {
    SeqList list = { {2, 4, 5, 7, 9}, 5 }; // ��ʼ��˳�������5��Ԫ��
    int x = 3; 
    printf("���������Ϊ 3");
    printf("����ǰ����: ");
    printSeqList(&list);

    // ���Բ��ұ����
    insertByLinear(&list, x); 

    printf("���Ա���Ҳ��������: ");
    printSeqList(&list);

    // ���ֲ��Ҳ���
    SeqList list2 = { {2, 4, 5, 2, 6}, 5 };
    printf("����ǰ����: ");
    printSeqList(&list2);
    insertByBinary(&list2, x);
    printf("���ַ����������: ");
    printSeqList(&list2);

    return 0;
}