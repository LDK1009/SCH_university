#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


typedef int element;

typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) 
{
	phead->llink = phead;
	phead->rlink = phead;

}

// ���ο� ��带 before�� �����ʿ� ����
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before; // newnode->before
	newnode->rlink = before->rlink; // newnode->after  * rlink�� after�� ����
	before->rlink->llink = newnode; // after�� newnode�� �������ϵ��� �� after->newnode
	before->rlink = newnode;		//befor->newnode
}

void print_dlist(DListNode *phead)
{
	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-|%d|->", p->data);

	}
	printf("\n");
}

//removed ��带 �����Ѵ�
void ddelete(DListNode* head, DListNode* removed)
{
	//��� ���� ���� �Ұ�
	if (removed == head)
		return;
	// head->removed->node -> .....
	removed->llink->rlink = removed->rlink; // removed ���� �� head -> node�� �����
	removed->rlink->llink = removed->llink; // node->head 

	free(removed);
}

int main()
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));

	init(head);


	dinsert(head, 0);
	print_dlist(head);
	dinsert(head, 1);
	print_dlist(head);
	dinsert(head, 2);
	print_dlist(head);
	dinsert(head, 3);
	print_dlist(head);
	dinsert(head, 4);
	print_dlist(head);

}