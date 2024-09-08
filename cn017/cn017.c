//statistics
#include<stdio.h>
void main()
{
	char c;
	int letternum = 0, digitnum = 0, spacenum = 0, othernum = 0;
	printf("Please enter character: \n");
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letternum++;
        }
        else if (c >= '0' && c <= '9') {
            digitnum++;
        }
        else if (c == ' ') {
            spacenum++;
        }
        else {
            othernum++;
        }
    }
	printf("letternum = %d, digitnum = %d, spacenum = %d, othernum = %d", letternum, digitnum, spacenum, othernum);
}