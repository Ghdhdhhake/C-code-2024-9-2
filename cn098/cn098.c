#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	char str[24] = {'\0'};
	printf("请输入一个字符串：\n");
	scanf("%s", str);
	size_t cout = strlen(str);
	int i = 0;
	while (i < cout)
	{
		str[i] = toupper(str[i]);
		i++;
	}
	printf("转换后的字符串为：%s", str);

}