#include<stdio.h>
#include<string.h>

char* deleteCharacters(char* str, char* charSet)
{
	int num[256] = {0};
	if (charSet == NULL)
		return str;
	for (int i = 0; i < strlen(charSet); i++)
	{
		num[(unsigned char)charSet[i]] = 1;
	}
	int currentIndex = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (!num[(unsigned char)str[i]]) 
		{
			str[currentIndex++] = str[i];
		}
	}
	str[currentIndex] = '\0';
	return str;
}
void main()
{
	char str1[] = "fejaiejriaa";
	char str2[] = "a";
	printf("%s\n", deleteCharacters(str1, str2));

}