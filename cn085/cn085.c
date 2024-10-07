//buggggggggggggggggggggggg
#include<stdio.h>
int IsPrime(int n);
void  main()
{
	int i, j, temp = 2;
	long int sum = 9;
	for (j = 2; j < 10000; j++)
	{
		temp = IsPrime(j);
		if (temp == 1)
		{
			for (i = 1; ; i++)
			{
				if (sum % j == 0)break;
				else sum = sum * 10 + 9;
			}
			printf("The prime number can divisible by %d\n", sum);
		}
		else
			break;
	}
}

int IsPrime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}