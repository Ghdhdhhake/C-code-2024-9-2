#include<stdio.h>
#define MAX
#define MAXIMUM(x, y) (x > y)? x:y
#define MINIMUM(x, y) (x < y)? x:y
void main()
{
	int a = 1, b = 2;
#ifdef MAX
	printf("Max = %d\n", MAXIMUM(a, b));
#else
	printf("Min = %d\n", MINIMUM(a.b));
#endif

#ifndef MIN
	printf("Min = %d\n", MINIMUM(a, b));
#else
	printf("Max = %d\n", MAXIMUM(a, b));
#endif

#undef MAX
#ifdef MAX
	printf("Max = %d\n", MAXIMUM(a, b));
#else
	printf("Min = %d\n", MINIMUM(a, b));
#endif

#define MIN
#ifndef MIN
	printf("Min = %d\n", MINIMUM(a, b));
#else
	printf("Max = %d\n", MAXIMUM(a, b));
#endif
}
