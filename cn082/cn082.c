#include <stdio.h>
#include<string.h>
#include<math.h>
int octalToDecimal(const char *p)
{
    int q = 0;
    int length = strlen(p);
    for (int i = 0; i < length; i++)
    {
        int digit = p[i] - '0';
        q += digit * pow(8, length - i -1);
    }
    return q;
}
int main() {
    char octalNumber[100];

 
    printf("请输入一个八进制数: ");
    scanf_s("%s", octalNumber);

    int decimalNumber = octalToDecimal(octalNumber);

    printf("八进制数 %s 转换为十进制数是: %d\n", octalNumber, decimalNumber);

    return 0;
}