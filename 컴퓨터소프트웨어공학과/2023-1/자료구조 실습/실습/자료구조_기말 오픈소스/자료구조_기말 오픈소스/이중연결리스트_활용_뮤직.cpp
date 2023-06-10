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

//현재 실행 곡 포인터
DListNode* current;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;

}

// 새로운 노드를 before의 오른쪽에 삽입
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	//newnode->data = data;
	strcpy(newnode->data, data);
	newnode->llink = before; // newnode->before
	newnode->rlink = before->rlink; // newnode->after  * rlink를 after에 연결
	before->rlink->llink = newnode; // after가 newnode를 포인터하도록 함 after->newnode
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

//removed 노드를 삭제한다
void ddelete(DListNode* head, DListNode* removed)
{
	//헤드 노드는 삭제 불가
	if (removed == head)
		return;
	// head->removed->node -> .....
	removed->llink->rlink = removed->rlink; // removed 삭제 후 head -> node로 변경됨
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
		printf("명령어(<,>,q):");
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