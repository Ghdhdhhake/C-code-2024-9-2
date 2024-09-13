#include<stdio.h>
void helloworld()
{
	printf("HELLO WORLD!!!!!!!!!\n");
}

void three_world()
{
	for (int i = 0; i < 3; i++)
	{
		helloworld();
	}
}
void main()
{
	three_world();
}