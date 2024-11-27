#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAXNUM 60

typedef struct {
    char ch;
    int weight; // Ȩֵ(Ƶ��)
    int parent;
    int left;
    int right;
} HuffNode;

typedef struct {
    char code[MAXNUM];
    int start;
} HuffCode;

HuffNode ht[MAXNUM * 2]; // �洢��������
HuffCode hcd[MAXNUM]; // ���ht�����ж�Ӧ�ַ��ı���

int n; // �ַ�������ȫ�ֱ���

void initHt() {
    FILE* fp;
    char ch;
    int i = 0;
    if ((fp = fopen("character.txt", "r")) == NULL) {
        printf("�޷����ļ�character.txt");
        exit(0);
    }
    //��ʼ�����н��
    for (i = 0; i < MAXNUM * 2; i++) {
        ht[i].left = ht[i].right = ht[i].parent = -1;
        ht[i].ch = '\0'; // ��ʼ�� ch Ϊ��Ч�ַ�
        ht[i].weight = 0; // ��ʼ�� weight Ϊ 0
    }
    //��ȡ�ַ�����Ȩ��
    i = 0;
    while (fscanf(fp, " %c %d", &ht[i].ch, &ht[i].weight) == 2) {
        i++;
    }
    n = i;

    if (fclose(fp)) {
        printf("�޷��ر��ļ�character.txt");
        exit(0);
    }
}

void createHuffTree() {
    int i = 0, k;
    int minI, minJ;
    int f = 0;
    minI = minJ = -1; // minI < minJ����ʼ����С�������
    for (k = n; k < 2 * n - 1; k++) {
        minI = minJ = -1;
        for (i = 0; i < k; i++) {
            if (ht[i].parent == -1) {//�ҵ�δ��ʹ�õĽ��
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
            ht[k].ch = '#';//�ϵ��ַ�
            ht[k].left = minI;
            ht[k].right = minJ;
            ht[k].weight = ht[minI].weight + ht[minJ].weight;//�����½��Ȩ��
            ht[k].parent = -1;//�½���޸��ڵ�
            ht[minI].parent = ht[minJ].parent = k;//������С��㸸�ڵ�
        }
    }
}
//�ַ�����ת
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
        while (ht[j].parent != -1) {//��Ҷ�ӽ����������ڵ�
            if (ht[ht[j].parent].left == j) {
                hcd[i].code[length++] = '0';//���֧����0
            }
            else {
                hcd[i].code[length++] = '1';//�ҷ�֧����Ϊ1
            }
            j = ht[j].parent;
        }
        hcd[i].code[length] = '\0';//�����ַ���
        reverse(hcd[i].code);//��ת�ַ�������
    }
    //�洢������
    if ((fp = fopen("code.txt", "w")) == NULL) {
        printf("�޷����ļ�code.txt");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%c  %s\n", ht[i].ch, hcd[i].code);
    }
    if (fclose(fp)) {
        printf("�޷��ر��ļ�code.txt");
        exit(0);
    }
}

int releaseHuffCode(char* str, char* code) {
    int root = 2 * n - 2;
    int length = 0, i = 0;
    int currentRoot = root; // ��ǰ���ڵ�

    while (code[i]) {
        if (code[i] == '0')
            currentRoot = ht[currentRoot].left;//���֧�ƶ�
        else if (code[i] == '1')
            currentRoot = ht[currentRoot].right;//�ҷ�֧�ƶ�
        else
            return 0; // �Ƿ��ַ�

        if (currentRoot == -1) // ����Ƿ���ʵ���Ч�ڵ�
            return 0;

        if (ht[currentRoot].left == -1 && ht[currentRoot].right == -1) {
            str[length++] = ht[currentRoot].ch;//�ҵ�Ҷ�ӽڵ�
            currentRoot = root; // ���õ�ǰ���ڵ�
        }
        i++;
    }
    str[length] = '\0';//�����ַ���

    if (currentRoot == root) // ����Ƿ�ص����ڵ�
        return 1;
    return 0;
}

void encode() {
    int i = 0, j, f = 1;
    char str[50];
    char code[500] = { '\0' };
    printf("\n������Ҫ������ַ�����length<50��\n");
    scanf("%s", str);
    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            for (j = 0; j < n; j++) {
                if (str[i] == ht[j].ch) {
                    strcat(code, hcd[j].code);
                    break;
                }
            }
            if (j == n) { // ���û���ҵ�ƥ����ַ�
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
        printf("������ַ�������\n");
    printf("���������ѡ��!\n");
    _getch();
}

void decode() {
    char str[50];
    char code[500];
    printf("\n��������Ҫ������ַ�������0��1��ʾ����\n");
    scanf("%s", code);
    if (releaseHuffCode(str, code))
        puts(str);
    else
        printf("�����ַ�������\n");
    printf("���������ѡ��!\n");
    _getch();
}

int main() {
    int choice = 1;
    initHt();//��ʼ����������
    createHuffTree();//������������
    createHuffCode();//���ɹ���������
    while (choice) {
        system("cls");
        printf("��character.txt�ļ��д���Ÿ�����ĸ��Ȩֵ\n");
        printf("�������������ĸ��Ȩֵ���������������\n");
        printf("�����ַ��ı�������code.txt��\n");
        printf("-------------------------------------------");
        printf("\n�������ѡ���1-���룻2-���룻0-�˳���\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: encode(); break;
        case 2: decode(); break;
        case 0: printf("������"); break;
        default:
            choice = 1;
            printf("���󣬰�������������룡\n");
            _getch();
            break;
        }
    }
    return 0;
}
