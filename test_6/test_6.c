#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datatype;
typedef struct node
{
	datatype elem;
	struct node* lchild;
	struct node* rchild;
}BTNode, *BinTree;


BinTree CreateTree();//���򴴽�������
void DelTree(BinTree root);//���ٶ�����
void display(BinTree root);//ʹ�����ŷ���ʾ������
void preOrder(BinTree root);//�ݹ�ǰ�����
void inOrder(BinTree root);//�ݹ��������
void postOrder(BinTree root);//�ݹ�������
int maxDepth(BinTree root);//�������������
BinTree Parent(BinTree bt, char NodeName);//��ѯ���ĸ��ڵ�
BinTree Search(BinTree bt, char NodeName);//����ĳ���ڵ�
int Nodes(BinTree bt);//ͳ�ƶ������Ľ����
void DispLeaf(BinTree bt);//������������е�Ҷ�ӽ��


int main()
{
	BinTree root = NULL;
	BinTree nn;
	char name;
	printf("��������Ҫ�����Ķ��������У�AB#D##CE##F##��:\n");
	root = CreateTree();
	printf("�����������\n");
	display(root);
	printf("\n�ö���������������Ϊ��");
	preOrder(root);
	printf("\n�ö���������������Ϊ��");
	inOrder(root);
	printf("\n�ö������ĺ�������Ϊ��");
	postOrder(root);
	int num = maxDepth(root);
	printf("\n\n�ö�����������Ϊ��%d\n", num);


	fflush(stdin);
	//while (getchar() != '\n');  // ���ǰһ������Ļ��з�, ���������

	printf("������Ҫ���ҵĽ������");
	scanf(" %c", &name);  // ע�� %c ǰ����һ���ո� ע�� %c ǰ����һ���ո�������ǰһ������Ļ��з���

	nn = Parent(root, name);
	if(nn)
		printf("%c�ĸ������Ϊ�� %c\n", name, nn->elem);
	nn = Search(root, name);
	if (nn->lchild)
		printf("%c ������Ϊ�� %c\n", name, nn->lchild->elem);
	else
		printf("%c �����ӡ�\n", name);
	if (nn->rchild)
		printf("%c ���Һ���Ϊ�� %c\n", name, nn->rchild->elem);
	else
		printf("%c ���Һ��ӡ�\n", name);
	printf("\n�˶������Ľ����Ϊ��%d��\n", Nodes(root));
	printf("\n������е�Ҷ�ӽ�㣺 \n");
	DispLeaf(root);
	fflush(stdin);

	return 0;
}
//�������д���������
BinTree CreateTree()
{
	BinTree bt = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch != '#')
	{
		bt = (BinTree)malloc(sizeof(BTNode));
		bt->elem = ch;
		bt->lchild = CreateTree();
		bt->rchild = CreateTree();
	}
	return bt;
}
//ɾ��������
void DelTree(BinTree root)
{
	if (root != NULL)
	{
		DelTree(root->lchild);
		DelTree(root->rchild);
	}
	free(root);
}
//���ŷ�ʽ��ʾ�������ṹ
void display(BinTree root)
{ 
	if (root != NULL)
	{
		printf("%c", root->elem);
		if (root->lchild != NULL || root->rchild != NULL)
		{
			printf("(");
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			printf(",");
			display(root->rchild);
			printf(")");
		}
	}
}
//�ݹ�ǰ���б���
void preOrder(BinTree root)
{
	if (root)
	{
		printf("%c", root->elem);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}
//�ݹ������б���
void inOrder(BinTree root)
{
	if (root)
	{
		inOrder(root->lchild);
		printf("%c", root->elem);
		inOrder(root->rchild);
	}
}
//�ݹ�����б���
void postOrder(BinTree root)
{
	if (root)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		printf("%c", root->elem);
	}
}
//�������������
int maxDepth(BinTree root)
{
	int m, n;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		m = maxDepth(root->lchild);
		n = maxDepth(root->rchild);
		if (m > n)
		{
			return (m + 1);
		}
		else
		{
			return (n + 1);
		}
	}
}
//��ѯĳ�����ĸ����
BinTree Parent(BinTree bt, char NodeName)
{
	if (bt)
	{
		if (bt->elem == NodeName)
		{
			printf("%c���Ϊ�����\n", NodeName);
			return NULL;
		}
	}
	if ((bt->lchild != NULL && bt->lchild->elem == NodeName) || (bt->rchild != NULL && bt->rchild->elem == NodeName))
		return bt;
	else
	{
		BTNode* tempP = NULL;
		if (bt->lchild)
			if (tempP = Parent(bt->lchild, NodeName))
				return tempP;
		if (bt->rchild)
			if (tempP = Parent(bt->rchild, NodeName))
				return tempP;
	}
	return NULL;
}

BinTree Search(BinTree bt, char NodeName)
{
	BinTree p;
	if (bt)
	{
		if (bt->elem == NodeName)
			return bt;
		if (bt->lchild)
		{
			p = Search(bt->lchild, NodeName);
			if (p)
				return p;
		}
		if (bt->rchild)
		{
			p = Search(bt->rchild, NodeName);
			if (p)
				return p;
		}
	}
	return NULL;
}
//ͳ�ƶ������еĽ����
int Nodes(BinTree bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	else
		return Nodes(bt->lchild) + Nodes(bt->rchild) + 1;
}
//���������������Ҷ�ӽڵ�
void DispLeaf(BinTree bt)
{
	if (bt != NULL)
	{
		if (bt->lchild == NULL && bt->rchild == NULL)
			printf("%3c", bt->elem);
		DispLeaf(bt->lchild);
		DispLeaf(bt->rchild);
	}
}