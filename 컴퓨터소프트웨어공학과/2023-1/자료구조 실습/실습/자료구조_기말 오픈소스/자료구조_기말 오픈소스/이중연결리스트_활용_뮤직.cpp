#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef char element[100];

typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

//���� ���� �� ������
DListNode* current;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;

}

// ���ο� ��带 before�� �����ʿ� ����
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	//newnode->data = data;
	strcpy(newnode->data, data);
	newnode->llink = before; // newnode->before
	newnode->rlink = before->rlink; // newnode->after  * rlink�� after�� ����
	before->rlink->llink = newnode; // after�� newnode�� �������ϵ��� �� after->newnode
	before->rlink = newnode;		//befor->newnode
}

void print_dlist(DListNode* phead)
{
	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		if (p == current)
			printf("<-|#%s#|->", p->data);
		else
			printf("<-|%s|->", p->data);
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
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));

	init(head);

	char song1[] = "Mamamia";
	char song2[] = "Dancing Queen";
	char song3[] = "Fernando";
	dinsert(head, song1);
	dinsert(head, song2);
	dinsert(head, song3);

	current = head->rlink;
	print_dlist(head);

	do {
		printf("��ɾ�(<,>,q):");
		ch = getchar();

		if (ch == '>')
		{
			current = current->rlink;

			if (current == head)
				current = current->rlink;
		}

		else if (ch == '<')
		{
			current = current->llink;

			if (current == head)
				current = current->llink;
		}

		print_dlist(head);
		getchar();

	} while (ch != 'q');

	free(head);
	return 0;

}