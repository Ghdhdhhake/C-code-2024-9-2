#include<stdio.h>
#include<malloc.h>
int minBottles(int students);

int main() {
    int n;
    int* arrey;
    printf("����������");
    scanf_s("%d", &n);
    arrey = (int*)malloc(n * sizeof(int));
    int x = 0;
    int i = 0;
    for ( i = 0; i < n; i++) {
        int   students;
        printf("����������ѧ������");
        scanf_s("%d", &students); // ��ȡÿ�������е�ѧ����  
        arrey[x] = minBottles(students);
        x++;
    }
    for ( i = 0; i < n; i++) {
        printf("���ٹ����ƿ����");
        printf("%d\n", arrey[i]);
    }
    return 0;
}

int minBottles(int students) {
    int bottlesBought = students;


    if (bottlesBought > 5) {
        int newBottles = bottlesBought / 5; // ������Ի��õ��¿�����  
        bottlesBought = bottlesBought - newBottles;
    }
    if (students % 5 == 0 && students > 5)
    {
        bottlesBought++;
    }


    return bottlesBought;
}
