#define  _CRT_SECURE_NO_WARNINGS
//？？？？？？？？？？？？？？
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE* fp=NULL;
	char filename[25] = {0};
	char ch= 'a';
	printf("请输入你需要保存的文件名称：\n");
	gets_s(filename, 25);
	if (fp = fopen(filename, "w") == NULL)
	{
		printf("Error");
		exit(0);
	}
	printf("请输入你需要保存的内容，以字符'#'结束：\n");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, fp);
	}
	fclose(fp);
	system("pause");
}