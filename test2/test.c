#include<stdio.h>
#include<stdlib.h>
//�����Ĵ�С
#define MaxSize 20
//��typedef ��int���������ΪElemType����˼�Ǳ���Ԫ�ص�type
typedef int ElemType;
//˳���ṹ���壬�����˱�ĳ��Ⱥ�һ������
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//����˳����ʼ������
int Init_SeqList(SeqList* L)
{
    L->length = 0;     //���ó���Ϊ0���ձ�
    //printf("%d",L->length);
    return 1;
}

//�������ĳ��Ԫ��λ�õĺ���
int Locate_SeqList(SeqList* L, int x)
{
    int i = 0;
    //�ӵ�0����ʼ�������������������Ǣ���������length�ˢ��ڱ����ҵ�ֵ�������ֵ�����
    for (i = 0; i < L->length && L->elem[i] != x; i++)
    {
        ;;
    }
    /* while(i<L->length&&L->elem[i]!=x)
         i++;*/

         //����ѭ������һ�����
    if (i >= L->length)
    {
        printf("˳����в����ڸ�Ԫ�أ�\n");
        return 0;
    }
    //�ڶ����������Ϊ�������飬���Է��ص�����Ӧ�ü�1
    else
        return i + 1;
}

//�������˳���ĺ������ڵ�i��Ԫ��֮ǰ����x
//ע�⣺���û���˵��1��������ĵ�0��
int Insert_SeqList(SeqList* L, int i, int x)
{
    int j;
    //printf("MaxSize\n");
    //printf("%d",MaxSize);
    //printf("%d",L.length);
    if (L->length >= MaxSize)
    {
        printf("˳����������޷����в��������");
        return 0;
    }
    else if (i <= 0 || i > L->length + 1)
    {
        printf("�����λ�ò���ȷ��");
        return 0;
    }
    //�����һ��Ԫ�ؿ�ʼ��һ��һ����������һλ����Ҫ�����Ԫ�������ռ�
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    //�ڵ�i��Ԫ��֮ǰ������ǰѴ�i��ʼ��Ԫ�������ƣ�Ȼ��ֵ����i��Ԫ�أ��������о���i-1��
    L->elem[i - 1] = x;
    L->length++; //������֮�����鳤��+1
    return 1;
}

//����ɾ��˳���Ԫ�غ�����ɾ����i��Ԫ��
int Delete_SeqList(SeqList* L, int i)
{
    int j;
    if ((i < 1) || (i > L->length))//�Ͳ�����һ�����ж�����
    {
        printf("ɾ��λ�ò���ȷ��");
        return 0;
    }
    //ɾ����i��Ԫ�ؾ��Ǵӵ�i��Ԫ�ؿ�ʼһ��һ���شӺ���ǰ����
    for (j = i; j < L->length; j++)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;//���鳤��-1
    return 1;
}

//������ʾ���Ա�ĺ���
int Display_SeqList(SeqList* L)
{
    int i;
    //һ��һ���ش�ӡ����
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
        //return 1; ���ش�����ʵ����Ҳ�Ѿ������ˣ�ֻ����ʾ����1��  (֮ǰ��һ��Сbug)
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
    //printf("��ʼ��\n����˳������£�");
    //printf("%d",L.length);
    //����Ԫ��5201314
    Insert_SeqList(&L, 1, 3);
    Insert_SeqList(&L, 2, 6);
    Insert_SeqList(&L, 3, 9);
    Insert_SeqList(&L, 4, 0);
    Insert_SeqList(&L, 5, -2);
    Insert_SeqList(&L, 6, 89);
    Insert_SeqList(&L, 7, 77);
    //printf("\n");
    while (i)//��֤һֱ����
    {
        printf("��ǰ��˳������£� ");
        Display_SeqList(&L);
        printf("\n");
        printf("    Main Menu         \n");
        printf("1������ָ��Ԫ��    \n");
        printf("2������Ԫ�ص�ָ��λ��   \n");
        printf("3��ɾ��ĳһָ��λ��Ԫ��   \n");
        printf("4������   \n");
        printf("0���˳�����      \n");
        printf("\n");
        printf("��������ѡ��Ĳ˵���<1, 2, 3, 0>:\n");
        scanf_s("%d", &i);
        switch (i)
        {
        case 1:
            printf("���������Ԫ�أ�");
            scanf_s("%d", &x);
            j = Locate_SeqList(&L, x);
            if (j != 0)//�ҵ�Ԫ�ط��ص���i+1,���Կ���ǰ�溯��
            {
                printf("ָ��Ԫ��λ���� %d", j);
            }
            printf("\n\n");
            break;
        case 2:
            printf("���������Ԫ��λ�ã�");
            scanf_s("%d", &k);
            printf("���������Ԫ��ֵ��");
            scanf_s("%d", &x);
            j = Insert_SeqList(&L, k, x);
            if (j != 0)
            {
                printf("�����˳���������ʾ��\n");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;
        case 3:
            printf("������ɾ��Ԫ��λ�ã�");
            scanf_s("%d", &k);
            j = Delete_SeqList(&L, k);
            if (j != 0)
            {
                printf("�����˳���������ʾ��\n");
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
            printf("��������~");
        }
    }
    return 0;
}

