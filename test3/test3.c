#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ѧ����Ϣ����
typedef struct {
	char xuehao[14];//ѧ��
	char name[20];//����
	int sex;//�Ա�:0ΪŮ��1Ϊ��
	char tel[14];//�绰
	char qq[12];//QQ
}ElemType;

//����
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Node, * LinkList;
//����ѧ����Ϣ
void in(Node* head) {
	LinkList p, q;
	q = head;
	int n;
	printf("������ѧ��������");
	scanf_s("%d", &n);
	printf("������ѧ����Ϣ��\n");
	for (int i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->next = NULL;
		printf("ѧ�ţ�");
		scanf_s("%s", p->data.xuehao, 14);
		printf("������");
		scanf_s("%s", p->data.name, 20);
		printf("�Ա�");
		scanf_s("%d", &p->data.sex);
		printf("�绰��");
		scanf_s("%s", p->data.tel, 14);
		printf("QQ��");
		scanf_s("%s", p->data.qq, 12);
		q->next = p;
		q = q->next;
		printf("------------------\n");
	}
	printf("************************\n");
}
//���ѧ����Ϣ
void out(Node* head) {
	LinkList p;
	p = head;
	printf("----------------ѧ����Ϣ��---------------\n");
	printf("ѧ��\t����\t�Ա�\t�ֻ�����\tQQ��\n");
	while (p->next != NULL) {
		p = p->next;
		printf("%s\t%s\t%d\t%s\t\t%s\n", p->data.xuehao, p->data.name, p->data.sex, p->data.tel, p->data.qq);
	}
	printf("-----------------------------------------\n");
}
//��ѯָ��ѧ����Ϣ
void search_1(Node* head) {
	LinkList p;
	p = head;
	int f = 0;
	char a[14];
	printf("�������ѯѧ��ѧ�ţ�");
	scanf_s("%s", a, 14);
	printf("----------------ѧ����Ϣ��---------------\n");
	printf("ѧ��\t����\t�Ա�\t����\t��ϵ��ʽ\n");
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->data.xuehao, a) == 0) {
			f = 1;
			printf("%s\t%s\t%d\t%s\t%s\n", p->data.xuehao, p->data.name, p->data.sex, p->data.tel, p->data.qq);
		}
	}
	if (f == 0) {
		printf("��ѧ����Ϣ�����ڣ���ѯʧ�ܣ�\n");
	}
}
//����ѧ����Ϣ
void insert(Node* head) {
	LinkList p, q, r;
	p = head;
	int a, i = 0;
	printf("���������λ�ã�");
	scanf_s("%d", &a);
	printf("-----------\n");
	while (p->next != NULL && i < a - 1) {
		p = p->next;
		i++;
	}
	r = p;
	q = (LinkList)malloc(sizeof(Node));
	printf("��ӵ�ѧ����Ϣ��\n");
	printf("ѧ�ţ�");
	scanf_s("%s", q->data.xuehao, 14);
	while (p->next != NULL) {
		p = p->next;
		if (p->data.xuehao == q->data.xuehao) {
			printf("��ѧ���ѱ�ʹ�ã�\n");
			return;
		}
	}
	printf("������");
	scanf_s("%s", p->data.name, 20);
	printf("�Ա�");
	scanf_s("%d", &p->data.sex);
	printf("�绰��");
	scanf_s("%s", p->data.tel, 14);
	printf("QQ��");
	scanf_s("%s", p->data.qq, 12);
	//����
	q->next = r->next;
	r->next = q;
	printf("����ɹ���\n");
}
//�޸�ѧ����Ϣ
void update(Node* head) {
	LinkList p;
	p = head;
	char a[14];
	printf("������Ҫ�޸�ѧ����ѧ�ţ�");
	scanf_s("%s", a, 14);
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->data.xuehao, a) == 0) {
			printf("�޸ĺ��������");
			scanf_s("%s", p->data.name, 20);
			printf("�޸ĺ���Ա�");
			scanf_s("%d", &p->data.sex);
			printf("�޸ĺ�ĵ绰��");
			scanf_s("%s", p->data.tel, 14);
			printf("�޸ĺ��QQ��");
			scanf_s("%s", p->data.qq, 12);
			printf("***************\n");
			printf("�޸ĳɹ���\n");
			printf("***************\n");
		}
	}
}
//ɾ��ѧ����Ϣ
void delete(Node* head) {
	LinkList p, q;
	p = head;
	char a[14];
	printf("������ɾ��ѧ����ѧ�ţ�");
	scanf_s("%s", a, 14);
	while (p->next != NULL) {
		if (strcmp(p->data.xuehao, a) == 0) {
			q = p->next;
			p->next = q->next;
			free(q);
			printf("ɾ���ɹ���\n");
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("ɾ��ʧ�ܣ�\n");
	}

}
//�˳�
void exit_1() {
	printf("�˳��ɹ���\n");
	exit(0);
}

int main() {
	Node* head;
	head = (LinkList)malloc(sizeof(Node));
	head->next = NULL;
	int select = -1;
	printf("1--------����ѧ����Ϣ------------\n");
	printf("2--------��ѯ����ѧ����Ϣ--------\n");
	printf("3--------��ѯĳ��ѧ����Ϣ--------\n");
	printf("4--------���ѧ����Ϣ------------\n");
	printf("5--------�޸�ѧ����Ϣ------------\n");
	printf("6--------ɾ��ѧ����Ϣ------------\n");
	printf("7--------�˳�--------------------\n");
	while (select != 0) {
		printf("���������ѡ�");
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