#include<stdio.h>
#include<stdlib.h>

void main()
{
	const char* s[] = {"feia", "xaga", "miui", "pipa", "magisk"};
	const char** p;
	int i;
	for (i = 0; i < 5; i++)
	{
		p = &s[i];
		printf("%s\n", *p);
	}
}