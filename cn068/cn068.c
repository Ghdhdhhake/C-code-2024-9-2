#include <stdio.h>
#include<stdlib.h>

//void shiftArray(int arr[], int n, int m) {
//    int* temp = (int *)malloc(sizeof(int)* n);
//
//    for (int i = n - m, j = 0; i < n; i++, j++) {
//        temp[j] = arr[i];
//    }    
//    for (int i = n - m - 1; i >= 0; i--) {
//        arr[i + m] = arr[i];
//    }
//
//    for (int i = 0; i < m; i++) {
//        arr[i] = temp[i];
//    }
//}


int main() {
    int n;

    printf("�������������� n��");
    scanf_s("%d", &n);
    int* arr = (int *)malloc(sizeof(int) * n);
  
  
    printf("������ %d ��������", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

 /*   printf("����������ƶ���λ�� m��");
    scanf_s("%d", &m);*/


    printf("�ƶ�������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}