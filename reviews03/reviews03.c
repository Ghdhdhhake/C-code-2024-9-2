#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SeqStack.h"

int main()
{
	char str[] = "({[()]()})"; // �����ַ���
	int length = sizeof(str) / sizeof(str[0]) - 1; // �����ַ������ȣ���ȥĩβ�� '\0'
	if (bracketCheck(str, length)) {
		printf("����ƥ��ɹ��ġ�\n");
	}
	else {
		printf("����ƥ��ʧ�ܡ�\n");
	}
	//SeqStack st;
	//int k, choice;
	//datatype x;
	//InitStack(&st);
	//convent(10, 2);


	//while (1)
	//{
	//	printf("���������ѡ��");
	//	scanf("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:printf("��ջ��");
	//		scanf("%d", &x);
	//		k = push(&st, x);
	//		if (k)printf("OK\n");
	//		else printf("��\n");
	//		break;
	//	case 2:
	//		k = pop(&st, &x);
	//		if (k)printf("��ջԪ��%d\n", x);
	//		else printf("��\n");
	//		break;
	//	case 3:
	//		k = gettop(&st, &x);
	//		if (k)printf("ջ��Ԫ��%d\n", x);
	//		else printf("��\n");
	//		break;
	//	default:
	//		exit(0);
	//		break;
	//	}
	//}
	return 0;
}