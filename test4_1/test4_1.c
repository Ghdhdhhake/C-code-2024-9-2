#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SeqStack.h"

int main()
{
	int choice;
	SeqStack st;
	int k;
	datatype x;
	InitStack(&st);
	printf("------------------------\n");
	printf("1����ջ-----------------\n");
	printf("2����ջ-----------------\n");
	printf("3��ջ��-----------------\n");
	printf("0���˳�-----------------\n");
	printf("------------------------\n");
	while (1) {
		printf("���������ѡ��:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("��������ջ����: ");
			scanf_s("%d", &x);
			k = push(&st, x);
			if (k) printf("��ջ����\n");
			else printf(" ջΪ��\n");
			/*getch();*/
			break;
		case 2:
			k = pop(&st, &x);
			if (k) printf("��ջ����=%d.\n", x);
			else printf(" ջΪ��\n");
			/*getch();*/
			break;
		case 3:
			k = gettop(&st, &x);
			if (k) printf("ջ��Ԫ��=%d.\n", x);
			else printf(" ջΪ��\n");
			/*getch();*/
			break;
		case 0:
			exit(0); break;
		}
	}
	return 0;
	/*int num, mode;
	puts("������һ��ʮ���������Լ���Ҫת���Ľ��ƣ�");
	scanf("%d %d", &num, &mode);
	Convent(num, mode);*/
}
