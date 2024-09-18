#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef struct {

    int data[MAXSIZE];
    int length;

} SeqList;


void InitList(SeqList* L) 
{
    L->length = 0;
}


void PrintList(SeqList L) 
{
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


int ListInsert(SeqList* L, int pos, int elem) 
{

    if (pos < 1 || pos > L->length + 1) {
        return 0;
    }


    if (L->length >= MAXSIZE) {
        return 0;
    }
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = elem;
    L->length++;
    return 1;
}


void MergeList(SeqList A, SeqList B, SeqList* C) {


    int i = 0, j = 0, k = 0;


    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            C->data[k++] = A.data[i++];
        }
        else {
             C->data[k++] = B.data[j++];
         }
    }
    while (i < A.length) {
        C->data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C->data[k++] = B.data[j++];
    }
    C->length = k;
}

int main() {

    SeqList A, B, C;

    InitList(&A);
    InitList(&B);
    InitList(&C);

    ListInsert(&A, 1, 29);
    ListInsert(&A, 2, 18);
    ListInsert(&A, 3, 12);
    ListInsert(&A, 4, 7);
    ListInsert(&A, 5, 6);

    ListInsert(&B, 1, 33);
    ListInsert(&B, 2, 22);
    ListInsert(&B, 3, 17);
    ListInsert(&B, 4, 12);
    ListInsert(&B, 5, 5);

    printf("List A:");
    PrintList(A);
    printf("List B:");
    PrintList(B);
    MergeList(A, B, &C);
    printf("Merged List:");
    PrintList(C);

    return 0;
}



