#include <stdio.h>

void findMaxAndSecondMax(int arr[], int n, int* max, int* second_max) {
    if (n < 2) {
        printf("Error\n");
        return;
    }
     *max = *second_max = arr[0]; // 初始化最大值和次大值为最小可能的整数

    for (int i = 0; i < n; i++) {
        if (arr[i] > *max) {
            *second_max = *max;
            *max = arr[i];
        }
        else if (arr[i] > *second_max && arr[i] != *max) {
            *second_max = arr[i];
        }
    }
}

void main() {
    int arr[] = { 12, 35, 10, 100, 34, 51, 87, 90, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, second_max;
    
    findMaxAndSecondMax(arr, n, &max, &second_max);
    printf("max = %d second_max = %d", max, second_max);
}
