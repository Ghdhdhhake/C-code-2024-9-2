#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAXNUM 60

typedef struct {
    char ch;
    int weight; // 权值(频率)
    int parent;
    int left;
    int right;
} HuffNode;

typedef struct {
    char code[MAXNUM];
    int start;
} HuffCode;

HuffNode ht[MAXNUM * 2]; // 存储哈夫曼树
HuffCode hcd[MAXNUM]; // 存放ht数组中对应字符的编码

int n; // 字符个数，全局变量

void initHt() {
    FILE* fp;
    char ch;
    int i = 0;
    if ((fp = fopen("character.txt", "r")) == NULL) {
        printf("无法打开文件character.txt");
        exit(0);
    }
    //初始化所有结点
    for (i = 0; i < MAXNUM * 2; i++) {
        ht[i].left = ht[i].right = ht[i].parent = -1;
        ht[i].ch = '\0'; // 初始化 ch 为无效字符
        ht[i].weight = 0; // 初始化 weight 为 0
    }
    //读取字符及其权重
    i = 0;
    while (fscanf(fp, " %c %d", &ht[i].ch, &ht[i].weight) == 2) {
        i++;
    }
    n = i;

    if (fclose(fp)) {
        printf("无法关闭文件character.txt");
        exit(0);
    }
}

void createHuffTree() {
    int i = 0, k;
    int minI, minJ;
    int f = 0;
    minI = minJ = -1; // minI < minJ，初始化最小结点索引
    for (k = n; k < 2 * n - 1; k++) {
        minI = minJ = -1;
        for (i = 0; i < k; i++) {
            if (ht[i].parent == -1) {//找到未被使用的结点
                if (minI == -1 || ht[i].weight < ht[minI].weight) {
                    minJ = minI;
                    minI = i;
                }
                else if (minJ == -1 || ht[i].weight < ht[minJ].weight) {
                    minJ = i;
                }
            }
        }
        if (minI != -1 && minJ != -1) {
            ht[k].ch = '#';//断点字符
            ht[k].left = minI;
            ht[k].right = minJ;
            ht[k].weight = ht[minI].weight + ht[minJ].weight;//设置新结点权重
            ht[k].parent = -1;//新结点无父节点
            ht[minI].parent = ht[minJ].parent = k;//更新最小结点父节点
        }
    }
}
//字符串反转
void reverse(char* str) {
    int i, j;
    char ch;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}

void createHuffCode() {
    int i, j, length;
    FILE* fp;
    for (i = 0; i < n; i++) {
        length = 0;
        j = i;
        while (ht[j].parent != -1) {//从叶子结点遍历到根节点
            if (ht[ht[j].parent].left == j) {
                hcd[i].code[length++] = '0';//左分支编码0
            }
            else {
                hcd[i].code[length++] = '1';//右分支编码为1
            }
            j = ht[j].parent;
        }
        hcd[i].code[length] = '\0';//结束字符串
        reverse(hcd[i].code);//反转字符串编码
    }
    //存储编码结果
    if ((fp = fopen("code.txt", "w")) == NULL) {
        printf("无法打开文件code.txt");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%c  %s\n", ht[i].ch, hcd[i].code);
    }
    if (fclose(fp)) {
        printf("无法关闭文件code.txt");
        exit(0);
    }
}

int releaseHuffCode(char* str, char* code) {
    int root = 2 * n - 2;
    int length = 0, i = 0;
    int currentRoot = root; // 当前根节点

    while (code[i]) {
        if (code[i] == '0')
            currentRoot = ht[currentRoot].left;//左分支移动
        else if (code[i] == '1')
            currentRoot = ht[currentRoot].right;//右分支移动
        else
            return 0; // 非法字符

        if (currentRoot == -1) // 检查是否访问到无效节点
            return 0;

        if (ht[currentRoot].left == -1 && ht[currentRoot].right == -1) {
            str[length++] = ht[currentRoot].ch;//找到叶子节点
            currentRoot = root; // 重置当前根节点
        }
        i++;
    }
    str[length] = '\0';//结束字符串

    if (currentRoot == root) // 检查是否回到根节点
        return 1;
    return 0;
}

void encode() {
    int i = 0, j, f = 1;
    char str[50];
    char code[500] = { '\0' };
    printf("\n请输入要编码的字符串（length<50）\n");
    scanf("%s", str);
    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            for (j = 0; j < n; j++) {
                if (str[i] == ht[j].ch) {
                    strcat(code, hcd[j].code);
                    break;
                }
            }
            if (j == n) { // 如果没有找到匹配的字符
                f = 0;
                break;
            }
            i++;
        }
        else {
            f = 0;
            break;
        }
    }
    if (f)
        puts(code);
    else
        printf("输入的字符串错误\n");
    printf("任意键重新选择!\n");
    _getch();
}

void decode() {
    char str[50];
    char code[500];
    printf("\n请输入你要解码的字符串（用0和1表示）：\n");
    scanf("%s", code);
    if (releaseHuffCode(str, code))
        puts(str);
    else
        printf("输入字符串错误！\n");
    printf("任意键重新选择!\n");
    _getch();
}

int main() {
    int choice = 1;
    initHt();//初始化哈夫曼树
    createHuffTree();//构建哈夫曼树
    createHuffCode();//生成哈夫曼编码
    while (choice) {
        system("cls");
        printf("在character.txt文件中存放着各个字母的权值\n");
        printf("程序读出各个字母的权值构造哈夫曼树编码\n");
        printf("各个字符的编码存放在code.txt中\n");
        printf("-------------------------------------------");
        printf("\n输入你的选项：（1-编码；2-解码；0-退出）\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: encode(); break;
        case 2: decode(); break;
        case 0: printf("结束！"); break;
        default:
            choice = 1;
            printf("错误，按任意键重新输入！\n");
            _getch();
            break;
        }
    }
    return 0;
}
