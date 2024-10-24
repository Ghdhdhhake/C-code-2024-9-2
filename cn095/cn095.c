#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct programing
{
	float constent;
	char* pointer;
};
void main()
{
	struct programing variable;
	char str[] = "²ËÄñ½Ì³Ì:https//:www.runoob.com";

	variable.constent = 1.23f;
	variable.pointer = str;

	printf("%f\n", variable.constent);
	printf("%s", variable.pointer);

}