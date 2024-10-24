//???
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int i, j, k, TLen, PLen, cout = 0;
	char T[50] = { 0 }, P[10] = {0};
	printf("请输入两个字符串， 母串在前，子串在后：\n");
	gets_s(T, 50);
	gets_s(P, 10);
	TLen = strlen(T);
	PLen = strlen(P);
	for (i = 0; i <= TLen - PLen; i++)
	{
		for (j = 0, k = i; j < PLen && P[j] == T[k]; j++, k++);
		if (j == PLen) cout++;
	}
	printf("%d\n", cout);
	system("pause");

}

