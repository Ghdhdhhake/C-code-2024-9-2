#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 100

typedef struct
{
	char data[MaxSize];
	int length;

}SqString;

//����ʼ��
void StrAssign(SqString* s, char str[]);
//���ƴ�
void StrCopy(SqString* s, SqString t);
//�󴮳�
int StrLength(SqString s);
//�жϴ��Ƿ����
int StrEqual(SqString s, SqString t);
//����������
SqString Concat(SqString s, SqString t);
//���Ӵ�
//���ش�s�дӵ�i(1<=i<=StrLength(s))���ַ���ʼ�ġ���������j�ַ�����Ӵ�
SqString SubStr(SqString s, int i, int j);
//�����룬���봮s�ĵ�i��λ�ò��봮t
int InsStr(SqString* s, int i, SqString t);
//��ɾ��
int DelStr(SqString* s, int i, int j);
//���滻���ڴ�s�У� �����г��ֵ��ִ�1���滻�ɴ�s2
SqString RepStrAll(SqString s, SqString s1, SqString s2);
//�����
void DisStr(SqString s);
//������ģʽƥ�䣺�����㷨
int Index(SqString s, SqString t);

void main()
{
	SqString s, s1, s2, s3, t;
	StrAssign(&s, "cdeabcdefabcdefg");
	StrAssign(&s1, "fab");
	StrAssign(&s2, "abmnfh");
	StrAssign(&s3, "");
	StrAssign(&t, "");
	puts("�����s:");
	DisStr(s);
	printf("��s�ĳ����ǣ�%d\n", s.length);
	InsStr(&s, 9, s1);
	puts("�����s����s1��Ĵ�:");
	DisStr(s);
	DelStr(&s, 2, 5);
	puts("���ɾ����s:");
	DisStr(s);
	puts("�����s1��s2:");
	DisStr(s1);
	DisStr(s2);
	s3 = Concat(s1, s2);
	puts("���s1+s2:");
	DisStr(s3);
	
	StrAssign(&s, "abcabcdabcdeabcdefabcdefg");
	StrAssign(&t, "abcdeabcdefab");
	puts("����µĴ�s�ʹ�t:");
	DisStr(s);
	DisStr(t);
	int pos = Index(s, t);
	printf("��t�ڴ�s�е�λ���ǣ�%d", pos);
}

//����ʼ��
void StrAssign(SqString* s, char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		s->data[i] = str[i];
		i++;
	}
	s->length = i;
}

//���ƴ�
void StrCopy(SqString* s, SqString t)
{
	int i;
	for (i = 0; i < t.length; i++)
	{
		s->data[i] = t.data[i];
	}
	s->length = t.length;
}

//�󴮳�
int StrLength(SqString s)
{
	return s.length;
}

//�жϴ��Ƿ����
int StrEqual(SqString s, SqString t)
{
	int i = 0;
	if (s.length != t.length)
		return 0;
	else
	{
		for (i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
				return 0;
		}
		return 1;
	}
}

//����������
SqString Concat(SqString s, SqString t)
{
	SqString r;
	int i, j;
	for (i = 0; i < s.length; i++)
		r.data[i] = s.data[i];
	for (j = 0; j < t.length; j++)
		r.data[s.length + j] = t.data[j];
	r.length = i + j;
	return r;
}

//���Ӵ�
//���ش�s�дӵ�i(1<=i<=StrLength(s))���ַ���ʼ�ġ���������j�ַ�����Ӵ�
SqString SubStr(SqString s, int i, int j)
{
	SqString t;
	int k;
	if (i < 1 || j > s.length || j < 1 || i + j > s.length + 1)
	{
		t.length = 0;//Error!!!
	}
	else
	{
		for (k = i - 1; k < i + j; k++)
		{
			t.data[k - i + 1] = s.data[k];
		}
		t.length = j;
	}
	return t;
}

//�����룬���봮s�ĵ�i��λ�ò��봮t
int InsStr(SqString* s, int i, SqString t)
{
	int j;
	if (i < 1 || i > s->length + 1)
		return 0;//Error!!!
	else
	{
		for (j = s->length - 1; j >= i - 1; j--)
			s->data[j + t.length] = s->data[j];
		for (j = 0; j < t.length; j++)
			s->data[i + j - 1] = t.data[j];//���봮t
		s->length = s->length + t.length;
		return 1;
	}
}

//��ɾ��
int DelStr(SqString* s, int i, int j)
{
	int k;
	if (i < 1 || i > s->length || j < 1 || i + j > s->length + 1)
		return 0;
	else
	{
		for (k = i + j - 1; k < s->length; k++)
			s->data[k - j] = s->data[k];
		s->length = s->length - j;
		return 1;
	}
}

//���滻���ڴ�s�У� �����г��ֵ��ִ�1���滻�ɴ�s2
SqString RepStrAll(SqString s, SqString s1, SqString s2)
{
	int i;
	i = Index(s, s1);
	while (i > 0)
	{
		DelStr(&s, i, s1.length);//ɾ���ִ�s1
		InsStr(&s, i, s2); //�����Ӵ�s2
		i = Index(s, s1);

	}
	return s;
}

//�����
void DisStr(SqString s)
{
	int i;
	for (i = 0; i < s.length; i++)
		printf("%c", s.data[i]);
	printf("\n");
}

//������ģʽƥ�䣺�����㷨
int Index(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length && j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else//����ȣ�ָ�����
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return i - t.length + 1;//���ص�һ���ַ�λ��
	else
		return -1;
}