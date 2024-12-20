#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strCompare(const char* S, const char* T);
void compareLengths(const char* S, const char* T);

int main() {
    char S[100], T[100];
    printf("�������һ���ַ���S: ");
    scanf("%s", S);
    printf("������ڶ����ַ���T: ");
    scanf("%s", T);
    int result = strCompare(S, T);
    if (result == 0) {
        printf("�����ַ���������һ�¡�\n");
    }
    else {
        printf("�����ַ��������ݲ�һ�¡�\n");
    }
    compareLengths(S, T);
    return 0;
}
// ʵ���ַ������ݱȽϺ���
int strCompare(const char* S, const char* T) {
    int i = 0;
    while (S[i] != '\0' && T[i] != '\0') {
        if (S[i] != T[i]) {
            return 1; // ���ݲ�һ��
        }
        i++;
    }
    // ����Ƿ������ַ����������˽�β
    if (S[i] == '\0' && T[i] == '\0') {
        return 0; // ����һ��
    }
    else {
        return 1; // ���ݲ�һ��
    }
}
// ʵ���ַ������ȱȽϺ���
void compareLengths(const char* S, const char* T) {
    int lengthS = 0;
    int lengthT = 0;
    // �����ַ���S�ĳ���
    while (S[lengthS] != '\0') {
        lengthS++;
    }
    // �����ַ���T�ĳ���
    while (T[lengthT] != '\0') {
        lengthT++;
    }
    printf("�ַ���S�ĳ���: %d\n", lengthS);
    printf("�ַ���T�ĳ���: %d\n", lengthT);
    if (lengthS > lengthT) {
        printf("�ַ���S���ַ���T����\n");
    }
    else if (lengthS < lengthT) {
        printf("�ַ���T���ַ���S����\n");
    }
    else {
        printf("�ַ���S���ַ���T�ĳ�����ȡ�\n");
    }
}
