#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define  N  10

//��������
void quick_sort(int* a, int low, int high)
{
	int i = low;	//��һλ
	int j = high;	//���һλ
	int key = a[i]; //����һ������Ϊ��׼ֵ-- ���ҵ�һ����׼ֵ

	while (i < j)
	{
		while (i < j && a[j] >= key)
		{
			j--;
		}
		a[i] = a[j];

		while (i < j && a[i] <= key)
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	if (i - 1 > low) 
	{
		quick_sort(a, low, i - 1);
	}

	if (i + 1 < high)
	{
		quick_sort(a, i + 1, high);
	}
}

//��������
int main(int argc, const char* argv[])
{
	//�����˸����飬��ʼ����һ������һ��ʮ����N �궨���� 10	
	int a[N] = { 10, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

	int i = 0;
	printf("����֮ǰ:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	putchar(10);//����

	//����-����
	quick_sort(a, 0, N - 1);//���飬0 ��9

	printf("����֮��:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	putchar(10);

	return 0;
}