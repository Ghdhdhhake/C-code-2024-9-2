#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


void  shellSort(int* a, int len)
{
	int i, j, k, tmp, gap;
	for (gap = len / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < len; j += gap)
			{
				tmp = a[j];
				k = j - gap;
				while (k >= 0 && a[k] > tmp) {
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = tmp;
			}
		}
	}
}
void main()
{
	int i, len, * a;
	printf("请输入要排的数的个数：");
	scanf("%d", &len);
	a = (int*)malloc(len * sizeof(int));
	printf("请输入要排的数：\n");
	for (i = 0; i < len; i++) {
		scanf("%d", &a[i]);
	}
	shellSort(a, len);
	printf("希尔升序排列后结果为：\n");
	for (i = 0; i < len; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

}