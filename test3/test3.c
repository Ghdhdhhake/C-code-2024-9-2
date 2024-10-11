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
		scanf_s("%s", p->data.xuehao, 14);
		printf("姓名：");
		scanf_s("%s", p->data.name, 20);
		printf("性别：");
		scanf_s("%d", &p->data.sex);
		printf("电话：");
		scanf_s("%s", p->data.tel, 14);
		printf("QQ：");
		scanf_s("%s", p->data.qq, 12);
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
	char a[14];
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
	LinkList p, q, r;
	p = head;
	int a, i = 0;
	printf("请输入插入位置：");
	scanf_s("%d", &a);
	printf("-----------\n");
	while (p->next != NULL && i < a - 1) {
		p = p->next;
		i++;
	}
	r = p;
	q = (LinkList)malloc(sizeof(Node));
	printf("添加的学生信息：\n");
	printf("学号：");
	scanf_s("%s", q->data.xuehao, 14);
	while (p->next != NULL) {
		p = p->next;
		if (p->data.xuehao == q->data.xuehao) {
			printf("该学号已被使用！\n");
			return;
		}
	}
	printf("姓名：");
	scanf_s("%s", p->data.name, 20);
	printf("性别：");
	scanf_s("%d", &p->data.sex);
	printf("电话：");
	scanf_s("%s", p->data.tel, 14);
	printf("QQ：");
	scanf_s("%s", p->data.qq, 12);
	//插入
	q->next = r->next;
	r->next = q;
	printf("插入成功！\n");
}
//修改学生信息
void update(Node* head) {
	LinkList p;
	p = head;
	char a[14];
	printf("请输入要修改学生的学号：");
	scanf_s("%s", a, 14);
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->data.xuehao, a) == 0) {
			printf("修改后的姓名：");
			scanf_s("%s", p->data.name, 20);
			printf("修改后的性别：");
			scanf_s("%d", &p->data.sex);
			printf("修改后的电话：");
			scanf_s("%s", p->data.tel, 14);
			printf("修改后的QQ：");
			scanf_s("%s", p->data.qq, 12);
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
	char a[14];
	printf("请输入删除学生的学号：");
	scanf_s("%s", a, 14);
	while (p->next != NULL) {
		if (strcmp(p->data.xuehao, a) == 0) {
			q = p->next;
			p->next = q->next;
			free(q);
			printf("删除成功！\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("删除失败！\n");
	}

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
	printf("4--------添加学生信息------------\n");
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