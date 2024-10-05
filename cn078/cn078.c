#include<stdio.h>
#include<stdlib.h>
struct man {
	char name[5];
	int age;
}
person[4] = {"hua", 18,"ming", 23, "ye", 18, "di", 15};

void main()
{
	struct man* p, *q;
	q = NULL;
	int num = 0;
	p = person;
	for (int i = 0; i < 4; i++)
	{
		if (num < p->age)
		{
			num = p->age;
			q = p;
		}
		p++;
	}
	printf("The oldest man is %s : %d", q->name, q->age);
}