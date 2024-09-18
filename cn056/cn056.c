#include<stdio.h>
#include<malloc.h>
int minBottles(int students);

int main() {
    int n;
    int* arrey;
    printf("输入组数：");
    scanf_s("%d", &n);
    arrey = (int*)malloc(n * sizeof(int));
    int x = 0;
    int i = 0;
    for ( i = 0; i < n; i++) {
        int   students;
        printf("输入这个组的学生数：");
        scanf_s("%d", &students); // 读取每组数据中的学生数  
        arrey[x] = minBottles(students);
        x++;
    }
    for ( i = 0; i < n; i++) {
        printf("最少购买的瓶数：");
        printf("%d\n", arrey[i]);
    }
    return 0;
}

int minBottles(int students) {
    int bottlesBought = students;


    if (bottlesBought > 5) {
        int newBottles = bottlesBought / 5; // 计算可以换得的新可乐数  
        bottlesBought = bottlesBought - newBottles;
    }
    if (students % 5 == 0 && students > 5)
    {
        bottlesBought++;
    }


    return bottlesBought;
}
