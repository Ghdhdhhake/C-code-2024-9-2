#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生信息定义
typedef struct {
	char xuehao[14];//学号
	char name[20];//姓名
	int sex;//性别:0为女，1为男
	char tel[14];//电话
	char qq[12];//QQ
}ElemType;

//链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Node, * LinkList;
//输入学生信息
void in(Node* head) {
	LinkList p, q;
	q = head;
	int n;
	printf("请输入学生人数：");
	scanf_s("%d", &n);
	printf("请输入学生信息：\n");
	for (int i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->next = NULL;
		printf("学号：");
		scanf("%s", p->data.xuehao);
		printf("姓名：");
		scanf("%s", p->data.name);
		printf("性别：");
		scanf("%d", &p->data.sex);
		printf("电话：");
		scanf("%s", p->data.tel);
		printf("QQ：");
		scanf("%s", p->data.qq);
		q->next = p;
		q = q->next;
		printf("------------------\n");
	}
	printf("************************\n");
}
//输出学生信息
void out(Node* head) {
	LinkList p;
	p = head;
	printf("----------------学生信息表---------------\n");
	printf("学号\t姓名\t性别\t手机号码\tQQ号\n");
	while (p->next != NULL) {
		p = p->next;
		printf("%s\t%s\t%d\t%s\t\t%s\n", p->data.xuehao, p->data.name, p->data.sex, p->data.tel, p->data.qq);
	}
	printf("-----------------------------------------\n");
}
//查询指定学生信息
void search_1(Node* head) {
	LinkList p;
	p = head;
	int f = 0;
	char a[14] = {0};
	printf("请输入查询学生学号：");
	scanf_s("%s", a, 14);
	printf("----------------学生信息表---------------\n");
	printf("学号\t姓名\t性别\t年龄\t联系方式\n");
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->data.xuehao, a) == 0) {
			f = 1;
			printf("%s\t%s\t%d\t%s\t%s\n", p->data.xuehao, p->data.name, p->data.sex, p->data.tel, p->data.qq);
		}
	}
	if (f == 0) {
		printf("该学生信息不存在，查询失败！\n");
	}
}
//插入学生信息
void insert(Node* head) {
	LinkList p, s;
	p = head;
	
	int a, j;
	j = 1;
	printf("请输入你要插入的位置：");
	scanf("%d", &a);
	while (p  && j < a) 
	{
		p = p->next;
		j++;
	}
	if ( j != a)
	{
		printf("Error\n");
		return;
	}
	s = (LinkList)malloc(sizeof(Node));
	printf("学号：");
	scanf("%14s", s->data.xuehao);  
	printf("姓名：");
	scanf("%20s", s->data.name); 
	printf("性别：");
	scanf("%d", &s->data.sex);
	printf("电话：");
	scanf("%14s", s->data.tel);  
	printf("QQ：");
	scanf("%12s", s->data.qq);    

	// 插入新节点  
	s->next = p->next;
	p->next = s;
	printf("插入成功！\n");
}
//修改学生信息
void update(Node* head) {
	LinkList p;
	p = head;
	char a[14] = {0};
	printf("请输入要修改学生的学号：");
	scanf("%s", a);
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->data.xuehao, a) == 0) {
			printf("修改后的姓名：");
			scanf("%s", p->data.name);
			printf("修改后的性别：");
			scanf("%d", &p->data.sex);
			printf("修改后的电话：");
			scanf("%s", p->data.tel);
			printf("修改后的QQ：");
			scanf("%s", p->data.qq);
			printf("***************\n");
			printf("修改成功！\n");
			printf("***************\n");
		}
	}
}
//删除学生信息
void delete(Node* head) {
	LinkList p, q;
	p = head;
	q = NULL;
	char a[14] = {0};
	printf("请输入删除学生的学号：");
	scanf("%s", a);
	if (p != NULL && strcmp(p->data.xuehao, a) == 0) {
		p = p->next;
		free(p);
		printf("删除成功！\n");
		return;
	}

	// 遍历链表寻找要删除的节点  
	while (p != NULL) {
		if (strcmp(p->data.xuehao, a) == 0) {
			q->next = p->next;
			free(p);
			printf("删除成功！\n");
			return;
		}
		q = p;
		p = p->next;
	}

	// 如果没有找到匹配的节点  
	printf("删除失败！\n");
}
//退出
void exit_1() {
	printf("退出成功！\n");
	exit(0);
}

int main() {
	Node* head;
	head = (LinkList)malloc(sizeof(Node));
	head->next = NULL;
	int select = -1;
	printf("1--------输入学生信息------------\n");
	printf("2--------查询所有学生信息--------\n");
	printf("3--------查询某个学生信息--------\n");
	printf("4--------插入学生信息------------\n");
	printf("5--------修改学生信息------------\n");
	printf("6--------删除学生信息------------\n");
	printf("7--------退出--------------------\n");
	while (select != 0) {
		printf("请输入操作选项：");
		scanf_s("%d", &select);
		printf("\n");
		switch (select) {
		case 1:in(head); break;
		case 2:out(head); break;
		case 3:search_1(head); break;
		case 4:insert(head); break;
		case 5:update(head); break;
		case 6:delete(head); break;
		case 7:exit_1(); break;
		}
	}
	return 0;
}