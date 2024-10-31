#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 100

typedef struct
{
	char data[MaxSize];
	int length;

}SqString;

//串初始化
void StrAssign(SqString* s, char str[]);
//复制串
void StrCopy(SqString* s, SqString t);
//求串长
int StrLength(SqString s);
//判断串是否相等
int StrEqual(SqString s, SqString t);
//连接两个串
SqString Concat(SqString s, SqString t);
//求子串
//返回串s中从第i(1<=i<=StrLength(s))个字符开始的、由连续个j字符组成子串
SqString SubStr(SqString s, int i, int j);
//串插入，插入串s的第i个位置插入串t
int InsStr(SqString* s, int i, SqString t);
//串删除
int DelStr(SqString* s, int i, int j);
//串替换：在串s中， 将所有出现的字串1均替换成串s2
SqString RepStrAll(SqString s, SqString s1, SqString s2);
//输出串
void DisStr(SqString s);
//基本串模式匹配：暴力算法
int Index(SqString s, SqString t);

void main()
{
	SqString s, s1, s2, s3, t;
	StrAssign(&s, "cdeabcdefabcdefg");
	StrAssign(&s1, "fab");
	StrAssign(&s2, "abmnfh");
	StrAssign(&s3, "");
	StrAssign(&t, "");
	puts("输出串s:");
	DisStr(s);
	printf("串s的长度是：%d\n", s.length);
	InsStr(&s, 9, s1);
	puts("输出串s插入s1后的串:");
	DisStr(s);
	DelStr(&s, 2, 5);
	puts("输出删除后串s:");
	DisStr(s);
	puts("输出串s1和s2:");
	DisStr(s1);
	DisStr(s2);
	s3 = Concat(s1, s2);
	puts("输出s1+s2:");
	DisStr(s3);
	
	StrAssign(&s, "abcabcdabcdeabcdefabcdefg");
	StrAssign(&t, "abcdeabcdefab");
	puts("输出新的串s和串t:");
	DisStr(s);
	DisStr(t);
	int pos = Index(s, t);
	printf("串t在串s中的位置是：%d", pos);
}

//串初始化
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

//复制串
void StrCopy(SqString* s, SqString t)
{
	int i;
	for (i = 0; i < t.length; i++)
	{
		s->data[i] = t.data[i];
	}
	s->length = t.length;
}

//求串长
int StrLength(SqString s)
{
	return s.length;
}

//判断串是否相等
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

//连接两个串
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

//求子串
//返回串s中从第i(1<=i<=StrLength(s))个字符开始的、由连续个j字符组成子串
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

//串插入，插入串s的第i个位置插入串t
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
			s->data[i + j - 1] = t.data[j];//插入串t
		s->length = s->length + t.length;
		return 1;
	}
}

//串删除
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

//串替换：在串s中， 将所有出现的字串1均替换成串s2
SqString RepStrAll(SqString s, SqString s1, SqString s2)
{
	int i;
	i = Index(s, s1);
	while (i > 0)
	{
		DelStr(&s, i, s1.length);//删除字串s1
		InsStr(&s, i, s2); //插入子串s2
		i = Index(s, s1);

	}
	return s;
}

//输出串
void DisStr(SqString s)
{
	int i;
	for (i = 0; i < s.length; i++)
		printf("%c", s.data[i]);
	printf("\n");
}

//基本串模式匹配：暴力算法
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
		else//不相等，指针回溯
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return i - t.length + 1;//返回第一个字符位置
	else
		return -1;
}