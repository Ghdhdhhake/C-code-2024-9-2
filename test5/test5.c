#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// ����˳�򴮵���󳤶�
#define MAXLEN 100

// ����˳�򴮵Ľṹ��
typedef struct {
    char data[MAXLEN];   // �洢�ַ���������
    int length;          // �ַ�����ʵ�ʳ���
} SeqString;

// ��ʼ��˳��
void InitSeqString(SeqString* ss, const char* str) {
    strncpy(ss->data, str, MAXLEN - 1); // �����ַ�����˳�򴮵����ݲ���
    ss->length = strlen(str);          // ����˳�򴮵ĳ���
    ss->data[ss->length] = '\0';       // ȷ���ַ����Կ��ַ���β
}

// ��ӡ˳�򴮵����ݼ��䳤��
void PrintSeqString(SeqString* ss, const char* msg) {
    printf("%s: %s, ����: %d\n", msg, ss->data, ss->length);
}

// ��ָ��λ�ò����ַ���
void InsertSeqString(SeqString* ss, const char* str, int pos) {
    if (pos >= 0 && pos <= ss->length && ss->length + strlen(str) < MAXLEN) {
        // �ƶ�ԭʼ�ַ����������ռ�
        memmove(&ss->data[pos + strlen(str)], &ss->data[pos], ss->length - pos + 1);
        // �������ַ���
        memcpy(&ss->data[pos], str, strlen(str));
        // ���³���
        ss->length += strlen(str);
        // ȷ���ַ����Կ��ַ���β
        ss->data[ss->length] = '\0';
    }
}

// ɾ��ָ��λ�ÿ�ʼ���Ӵ�
void DeleteSubString(SeqString* ss, int startPos, int length) {
    if (startPos >= 0 && startPos < ss->length && startPos + length <= ss->length) {
        // �ƶ�ʣ���ַ����Ը��Ǳ�ɾ���Ĳ���
        memmove(&ss->data[startPos], &ss->data[startPos + length], ss->length - startPos - length + 1);
        // ���³���
        ss->length -= length;
        // ȷ���ַ����Կ��ַ���β
        ss->data[ss->length] = '\0';
    }
}

// ��������˳��
void ConcatSeqString(SeqString* ss, SeqString* ss2) {
    if (ss->length + ss2->length < MAXLEN) {
        strcat(ss->data, ss2->data);
        ss->length += ss2->length;
    }
    else {
        printf("Error: Concatenation would exceed maximum length.\n");
    }
}






// ��ƥ���㷨�ҵ�ģʽ���������е�λ��
int SimpleMatch(SeqString* ss, SeqString* t) {
    for (int i = 0; i <= ss->length - t->length; i++) {
        if (strncmp(ss->data + i, t->data, t->length) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    SeqString s, s1, s2, s3, t;
    InitSeqString(&s, "cdeabcdefabcdefg");    // ��ʼ��˳��s
    InitSeqString(&s1, "fab");               // ��ʼ��˳��s1
    InitSeqString(&s2, "abmnfh");            // ��ʼ��˳��s2

    // (2) �����s
    PrintSeqString(&s, "ԭʼ��s");
    PrintSeqString(&s1, "ԭʼ��s1");
    PrintSeqString(&s2, "ԭʼ��s2");

    //(3) �����s�ĳ���
    printf("��s�ĳ���: %d\n", s.length);

    // (4) �ڴ�s�ĵ�9���ַ�λ�ò��봮s1
    InsertSeqString(&s, s1.data, 8);

    // (5) �����s
    PrintSeqString(&s, "����s1��Ĵ�s");

    // (6) ɾ����s��2���ַ���ʼ�ĳ���Ϊ5���Ӵ�
    DeleteSubString(&s, 2, 5);

    // (7) �����s
    PrintSeqString(&s, "ɾ���Ӵ���Ĵ�s");

    // (8) ����s1�ʹ�s2���������������µĴ�s3
    InitSeqString(&s3, "");
    ConcatSeqString(&s3, &s1);
    ConcatSeqString(&s3, &s2);

    // (9)�����s3
    PrintSeqString(&s3, "s3 = s1 + s2");

    // (10) ���ü�ƥ���㷨��t��s�е�λ��
    InitSeqString(&s, "abcabcdabcdeabcdefabcdefg"); // ���³�ʼ����s
    InitSeqString(&t, "abcdeabcdefab");             // ��ʼ����t
    PrintSeqString(&s, "�µ�ԭʼ��s");
    PrintSeqString(&t, "ԭʼ��t");
    int pos = SimpleMatch(&s, &t);
    printf("��t��s�е�λ��: %d\n", pos);

    return 0;
}