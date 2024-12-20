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


BinTree CreateTree();//先序创建二叉树
void DelTree(BinTree root);//销毁二叉树
void display(BinTree root);//使用括号法显示二叉树
void preOrder(BinTree root);//递归前序遍历
void inOrder(BinTree root);//递归中序遍历
void postOrder(BinTree root);//递归后序遍历
int maxDepth(BinTree root);//求二叉树最大深度
BinTree Parent(BinTree bt, char NodeName);//查询结点的父节点
BinTree Search(BinTree bt, char NodeName);//查找某个节点
int Nodes(BinTree bt);//统计二叉树的结点数
void DispLeaf(BinTree bt);//输出二叉树所有的叶子结点


int main()
{
	BinTree root = NULL;
	BinTree nn;
	char name;
	printf("请输入你要创建的二叉树序列（AB#D##CE##F##）:\n");
	root = CreateTree();
	printf("输出二叉树：\n");
	display(root);
	printf("\n该二叉树的先序排列为：");
	preOrder(root);
	printf("\n该二叉树的中序排列为：");
	inOrder(root);
	printf("\n该二叉树的后序排列为：");
	postOrder(root);
	int num = maxDepth(root);
	printf("\n\n该二叉树最大深度为：%d\n", num);


	fflush(stdin);
	//while (getchar() != '\n');  // 清除前一次输入的换行符, 清除缓冲区

	printf("请输入要查找的结点名：");
	scanf(" %c", &name);  // 注意 %c 前面有一个空格， 注意 %c 前面有一个空格）来忽略前一次输入的换行符。

	nn = Parent(root, name);
	if(nn)
		printf("%c的父结点名为： %c\n", name, nn->elem);
	nn = Search(root, name);
	if (nn->lchild)
		printf("%c 的左孩子为： %c\n", name, nn->lchild->elem);
	else
		printf("%c 无左孩子。\n", name);
	if (nn->rchild)
		printf("%c 的右孩子为： %c\n", name, nn->rchild->elem);
	else
		printf("%c 无右孩子。\n", name);
	printf("\n此二叉树的结点数为：%d。\n", Nodes(root));
	printf("\n输出所有的叶子结点： \n");
	DispLeaf(root);
	fflush(stdin);

	return 0;
}
//先序序列创建二叉树
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
//删除二叉树
void DelTree(BinTree root)
{
	if (root != NULL)
	{
		DelTree(root->lchild);
		DelTree(root->rchild);
	}
	free(root);
}
//括号方式显示二叉树结构
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
//递归前序列遍历
void preOrder(BinTree root)
{
	if (root)
	{
		printf("%c", root->elem);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}
//递归中序列遍历
void inOrder(BinTree root)
{
	if (root)
	{
		inOrder(root->lchild);
		printf("%c", root->elem);
		inOrder(root->rchild);
	}
}
//递归后序列遍历
void postOrder(BinTree root)
{
	if (root)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		printf("%c", root->elem);
	}
}
//求二叉树最大深度
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
//查询某个结点的父结点
BinTree Parent(BinTree bt, char NodeName)
{
	if (bt)
	{
		if (bt->elem == NodeName)
		{
			printf("%c结点为根结点\n", NodeName);
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
//统计二叉树中的结点数
int Nodes(BinTree bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	else
		return Nodes(bt->lchild) + Nodes(bt->rchild) + 1;
}
//输出二叉树的所有叶子节点
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