//char temp = *left;
//*left = *right;
//*right = temp;
//????????????????
#include<stdio.h>

char* gets(char* str);
void main()
{
	char str[256] = {0};
	gets(str);
	int num = (int)strlen(str);
	char* left = str;
	char* right = str + num - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		right--;
		left++;
	}
	printf("%s", str);
}