#include <stdio.h>
#include <stdlib.h>

//����һ�����͵�����
typedef char datatype;
//������ṹ��
typedef struct node {
	datatype data;
	struct node* next;
}linklist;

linklist* CreatListR() {
	//��ͷ����ͷ�巨�����ص������ͷָ��
	linklist* head, * p, * r;
	datatype ch;
	head = (linklist*)malloc(sizeof(linklist));//����ͷ���
	head->next = NULL;//�����ձ�
	r = head;//rָ��ָ��ͷ���
	while ((ch = getchar()) != '\n') {
		p = (linklist*)malloc(sizeof(linklist));//�����½��
		p->data = ch;//�Խ�����������и�ֵ
		r->next = p;
		r = p;

	}
	r->next = NULL;
	return head;
}

linklist* Get(linklist* head, int i) {
	linklist* p = head;//pָ��ͷ���
	int j = 0;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (i == j) {
		return p;
	}
	else {
		return NULL;
	}
}
//������
int main() {
	linklist* head = (linklist*)malloc(sizeof(linklist));
	linklist* p = (linklist*)malloc(sizeof(linklist));
	head = CreatListR();
	int i;
	scanf_s("%d", &i);
	p = Get(head, i);
	if (p != NULL) {
		printf("%c", p->data);
	}
	else {
		printf("��������Χ��\n");
	}
	system("pause");
	return 0;
}