//c6031 ·µ»ØÖµ±»ºöÂÔ:"getchar()" ???????????
#include<stdio.h>

void main()
{
	char a, b;
	printf("Please enter first alphabet:");
	scanf_s("%c", &a, 1);
	getchar();
	switch (a)
	{
	case 'm':printf("Monday"); break;
	case 'w':printf("Wednesday"); break;
	case 'f':printf("Firday"); break;
	case 't':
		printf("Please enter second alphabet:");
		scanf_s("%c", &b, 1);
		if (b == 'u') { printf("Tuesday"); break;}
		if (b == 'h') { printf("Thursday"); break;}
	case 's':
		printf("Please enter second alphabet:");
		scanf_s("%c", &b, 1);
		if (b == 'u') { printf("Sunday"); break; }
		if (b == 'a') { printf("Saturday"); break; }
	default:break;
	}
}