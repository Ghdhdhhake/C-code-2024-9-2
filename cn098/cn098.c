#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	char str[24] = {'\0'};
	printf("������һ���ַ�����\n");
	scanf("%s", str);
	size_t cout = strlen(str);
	int i = 0;
	while (i < cout)
	{
		str[i] = toupper(str[i]);
		i++;
	}
	printf("ת������ַ���Ϊ��%s", str);

}