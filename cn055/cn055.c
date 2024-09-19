#include<stdio.h>
void main()
{
	char line[150];
	int i, j;
	printf("ÊäÈë×Ö·û´®£º\n");
	fgets(line,(sizeof line / sizeof line[0]), stdin);
	for ( i = 0; line[i] != '\0'; i++)
	{
		while (!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || line[i] == '\0'))
		{
			for (j = i; line[j] != '\0'; j++)
			{
				line[j] = line[j + 1];
			}
			line[j] = '\0';
		}
	}
	puts(line);
}