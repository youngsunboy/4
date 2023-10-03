#include <stdio.h>
#include <stdlib.h>

//定义一个类型的新名
typedef char datatype;
//单链表结构体
typedef struct node {
	datatype data;
	struct node* next;
}linklist;

linklist* CreatListR() {
	//带头结点的头插法，返回单链表的头指针
	linklist* head, * p, * r;
	datatype ch;
	head = (linklist*)malloc(sizeof(linklist));//产生头结点
	head->next = NULL;//建立空表
	r = head;//r指针指向头结点
	while ((ch = getchar()) != '\n') {
		p = (linklist*)malloc(sizeof(linklist));//生成新结点
		p->data = ch;//对结点的数据域进行赋值
		r->next = p;
		r = p;

	}
	r->next = NULL;
	return head;
}

linklist* Get(linklist* head, int i) {
	linklist* p = head;//p指向头结点
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
//主函数
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
		printf("超出链表范围！\n");
	}
	system("pause");
	return 0;
}