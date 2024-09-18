#include<stdio.h>
#include<stdlib.h>
//定义表的大小
#define MaxSize 20
//用typedef 给int定义个名字为ElemType，意思是表中元素的type
typedef int ElemType;
//顺序表结构定义，包括了表的长度和一个数组
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//定义顺序表初始化函数
int Init_SeqList(SeqList* L)
{
    L->length = 0;     //设置长度为0，空表
    //printf("%d",L->length);
    return 1;
}

//定义查找某个元素位置的函数
int Locate_SeqList(SeqList* L, int x)
{
    int i = 0;
    //从第0个开始到最后结束，结束条件是①索引到了length了②在表中找到值与输入的值相等了
    for (i = 0; i < L->length && L->elem[i] != x; i++)
    {
        ;;
    }
    /* while(i<L->length&&L->elem[i]!=x)
         i++;*/

         //结束循环，第一种情况
    if (i >= L->length)
    {
        printf("顺序表中不存在该元素！\n");
        return 0;
    }
    //第二种情况，因为这是数组，所以返回的序数应该加1
    else
        return i + 1;
}

//定义插入顺序表的函数：在第i个元素之前插入x
//注意：对用户来说第1个是数组的第0个
int Insert_SeqList(SeqList* L, int i, int x)
{
    int j;
    //printf("MaxSize\n");
    //printf("%d",MaxSize);
    //printf("%d",L.length);
    if (L->length >= MaxSize)
    {
        printf("顺序表已满，无法进行插入操作！");
        return 0;
    }
    else if (i <= 0 || i > L->length + 1)
    {
        printf("插入的位置不正确！");
        return 0;
    }
    //从最后一个元素开始，一个一个地往后移一位，给要插入的元素留出空间
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    //在第i个元素之前插入就是把从i开始的元素往后移，然后赋值给第i个元素，在数组中就是i-1了
    L->elem[i - 1] = x;
    L->length++; //插入完之后数组长度+1
    return 1;
}

//定义删除顺序表元素函数，删除第i个元素
int Delete_SeqList(SeqList* L, int i)
{
    int j;
    if ((i < 1) || (i > L->length))//和插入是一样的判断条件
    {
        printf("删除位置不正确！");
        return 0;
    }
    //删除第i个元素就是从第i个元素开始一个一个地从后向前覆盖
    for (j = i; j < L->length; j++)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;//数组长度-1
    return 1;
}

//定义显示线性表的函数
int Display_SeqList(SeqList* L)
{
    int i;
    //一个一个地打印出来
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
        //return 1; 严重错误，其实插入也已经插入了，只是显示出来1个  (之前的一个小bug)
    }
    return 1;
}


int main()
{


    SeqList L;
 /*   ElemType e, x;
    int i = 1, k, j, n, ii;*/
    ElemType x;
    int i = 1, k, j;
    Init_SeqList(&L);
    //printf("%d",Init_SeqList(&L));
    //printf("初始化\n建立顺序表如下：");
    //printf("%d",L.length);
    //插入元素5201314
    Insert_SeqList(&L, 1, 3);
    Insert_SeqList(&L, 2, 6);
    Insert_SeqList(&L, 3, 9);
    Insert_SeqList(&L, 4, 0);
    Insert_SeqList(&L, 5, -2);
    Insert_SeqList(&L, 6, 89);
    Insert_SeqList(&L, 7, 77);
    //printf("\n");
    while (i)//保证一直进行
    {
        printf("当前的顺序表如下： ");
        Display_SeqList(&L);
        printf("\n");
        printf("    Main Menu         \n");
        printf("1：查找指定元素    \n");
        printf("2：插入元素到指定位置   \n");
        printf("3：删除某一指定位置元素   \n");
        printf("4：清屏   \n");
        printf("0：退出程序      \n");
        printf("\n");
        printf("请输入你选择的菜单号<1, 2, 3, 0>:\n");
        scanf_s("%d", &i);
        switch (i)
        {
        case 1:
            printf("请输入查找元素：");
            scanf_s("%d", &x);
            j = Locate_SeqList(&L, x);
            if (j != 0)//找到元素返回的是i+1,可以看看前面函数
            {
                printf("指定元素位置是 %d", j);
            }
            printf("\n\n");
            break;
        case 2:
            printf("请输入插入元素位置：");
            scanf_s("%d", &k);
            printf("请输入插入元素值：");
            scanf_s("%d", &x);
            j = Insert_SeqList(&L, k, x);
            if (j != 0)
            {
                printf("插入后顺序表如下显示：\n");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;
        case 3:
            printf("请输入删除元素位置：");
            scanf_s("%d", &k);
            j = Delete_SeqList(&L, k);
            if (j != 0)
            {
                printf("插入后顺序表如下显示：\n");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;
        case 4:
            system("cls");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误~");
        }
    }
    return 0;
}

