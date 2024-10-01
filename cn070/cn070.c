#include<stdio.h>
int length(char* p);



void main()
{
	char str[100] = {0};
	unsigned int len = sizeof(str) / sizeof(str[0]);
	scanf_s("%s", str, len);
	int a = length(str);
	printf("The length of str is %d.", a);
}

int length(char* p)
{
	int i = 0;
	while (*p != '\0')
	{
		i++;
		p++;
	}
	return i;
}