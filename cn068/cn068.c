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

    printf("请输入整数个数 n：");
    scanf_s("%d", &n);
    int* arr = (int *)malloc(sizeof(int) * n);
  
  
    printf("请输入 %d 个整数：", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

 /*   printf("请输入向后移动的位置 m：");
    scanf_s("%d", &m);*/


    printf("移动后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}