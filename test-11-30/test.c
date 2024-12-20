#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strCompare(const char* S, const char* T);
void compareLengths(const char* S, const char* T);

int main() {
    char S[100], T[100];
    printf("请输入第一个字符串S: ");
    scanf("%s", S);
    printf("请输入第二个字符串T: ");
    scanf("%s", T);
    int result = strCompare(S, T);
    if (result == 0) {
        printf("两个字符串的内容一致。\n");
    }
    else {
        printf("两个字符串的内容不一致。\n");
    }
    compareLengths(S, T);
    return 0;
}
// 实现字符串内容比较函数
int strCompare(const char* S, const char* T) {
    int i = 0;
    while (S[i] != '\0' && T[i] != '\0') {
        if (S[i] != T[i]) {
            return 1; // 内容不一致
        }
        i++;
    }
    // 检查是否两个字符串都到达了结尾
    if (S[i] == '\0' && T[i] == '\0') {
        return 0; // 内容一致
    }
    else {
        return 1; // 内容不一致
    }
}
// 实现字符串长度比较函数
void compareLengths(const char* S, const char* T) {
    int lengthS = 0;
    int lengthT = 0;
    // 计算字符串S的长度
    while (S[lengthS] != '\0') {
        lengthS++;
    }
    // 计算字符串T的长度
    while (T[lengthT] != '\0') {
        lengthT++;
    }
    printf("字符串S的长度: %d\n", lengthS);
    printf("字符串T的长度: %d\n", lengthT);
    if (lengthS > lengthT) {
        printf("字符串S比字符串T长。\n");
    }
    else if (lengthS < lengthT) {
        printf("字符串T比字符串S长。\n");
    }
    else {
        printf("字符串S和字符串T的长度相等。\n");
    }
}
