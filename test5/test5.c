#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 定义顺序串的最大长度
#define MAXLEN 100

// 定义顺序串的结构体
typedef struct {
    char data[MAXLEN];   // 存储字符串的数据
    int length;          // 字符串的实际长度
} SeqString;

// 初始化顺序串
void InitSeqString(SeqString* ss, const char* str) {
    strncpy(ss->data, str, MAXLEN - 1); // 复制字符串到顺序串的数据部分
    ss->length = strlen(str);          // 设置顺序串的长度
    ss->data[ss->length] = '\0';       // 确保字符串以空字符结尾
}

// 打印顺序串的内容及其长度
void PrintSeqString(SeqString* ss, const char* msg) {
    printf("%s: %s, 长度: %d\n", msg, ss->data, ss->length);
}

// 在指定位置插入字符串
void InsertSeqString(SeqString* ss, const char* str, int pos) {
    if (pos >= 0 && pos <= ss->length && ss->length + strlen(str) < MAXLEN) {
        // 移动原始字符串以留出空间
        memmove(&ss->data[pos + strlen(str)], &ss->data[pos], ss->length - pos + 1);
        // 插入新字符串
        memcpy(&ss->data[pos], str, strlen(str));
        // 更新长度
        ss->length += strlen(str);
        // 确保字符串以空字符结尾
        ss->data[ss->length] = '\0';
    }
}

// 删除指定位置开始的子串
void DeleteSubString(SeqString* ss, int startPos, int length) {
    if (startPos >= 0 && startPos < ss->length && startPos + length <= ss->length) {
        // 移动剩余字符串以覆盖被删除的部分
        memmove(&ss->data[startPos], &ss->data[startPos + length], ss->length - startPos - length + 1);
        // 更新长度
        ss->length -= length;
        // 确保字符串以空字符结尾
        ss->data[ss->length] = '\0';
    }
}

// 连接两个顺序串
void ConcatSeqString(SeqString* ss, SeqString* ss2) {
    if (ss->length + ss2->length < MAXLEN) {
        strcat(ss->data, ss2->data);
        ss->length += ss2->length;
    }
    else {
        printf("Error: Concatenation would exceed maximum length.\n");
    }
}






// 简单匹配算法找到模式串在主串中的位置
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
    InitSeqString(&s, "cdeabcdefabcdefg");    // 初始化顺序串s
    InitSeqString(&s1, "fab");               // 初始化顺序串s1
    InitSeqString(&s2, "abmnfh");            // 初始化顺序串s2

    // (2) 输出串s
    PrintSeqString(&s, "原始串s");
    PrintSeqString(&s1, "原始串s1");
    PrintSeqString(&s2, "原始串s2");

    //(3) 输出串s的长度
    printf("串s的长度: %d\n", s.length);

    // (4) 在串s的第9个字符位置插入串s1
    InsertSeqString(&s, s1.data, 8);

    // (5) 输出串s
    PrintSeqString(&s, "插入s1后的串s");

    // (6) 删除串s第2个字符开始的长度为5的子串
    DeleteSubString(&s, 2, 5);

    // (7) 输出串s
    PrintSeqString(&s, "删除子串后的串s");

    // (8) 将串s1和串s2连接起来而产生新的串s3
    InitSeqString(&s3, "");
    ConcatSeqString(&s3, &s1);
    ConcatSeqString(&s3, &s2);

    // (9)输出串s3
    PrintSeqString(&s3, "s3 = s1 + s2");

    // (10) 采用简单匹配算法求t在s中的位置
    InitSeqString(&s, "abcabcdabcdeabcdefabcdefg"); // 重新初始化串s
    InitSeqString(&t, "abcdeabcdefab");             // 初始化串t
    PrintSeqString(&s, "新的原始串s");
    PrintSeqString(&t, "原始串t");
    int pos = SimpleMatch(&s, &t);
    printf("串t在s中的位置: %d\n", pos);

    return 0;
}