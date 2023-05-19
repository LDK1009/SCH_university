#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

typedef struct CListType
{
	ListNode* head;
	int nodeCount;
} CListType;

ListNode* insert_last(CListType* L, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	// memory allocation check routine

	strcpy(node->data, data);

	if (L->head == NULL)
	{
		L->head = node;
		// node->link = NULL 은 단순 연결 리스트 head -> node -> NULL 모양
		node->link = L->head; // 원형 리스트의 키 포인트! 헤드도 노드를 포인트 노드도 나를 포인트 head<->node 모양처럼 구현
	}

	else  //head->20->30
	{
		node->link = L->head->link;
		L->head->link = node;
		L->head = node;
	}

	return L->head;

}

ListNode* insert_first(CListType* L, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	// memory allocation check routine

	strcpy(node->data, data);


	if (L->head == NULL)
	{
		L->head = node;
		// node->link = NULL 은 단순 연결 리스트 head -> node -> NULL 모양
		node->link = L->head; // 원형 큐의 키 포인트! 헤드도 노드를 포인트 노드도 나를 포인트 head<->node 모양처럼 구현
	}

	else
	{
		node->link = L->head->link;  // 신규 노드의 링크를 기존 헤드 노드에 연결한다 즉, 신규 노드가 기존 헤드 노드 앞에 온다  * head->link는 기존의 1번 노드 포인터
		L->head->link = node;		// head<->node 구현
	}

	return L->head;
}

void print_list(CListType* L)
{
	ListNode* p;

	if (L->head == NULL)
	{
		return;
	}

	p = L->head->link;

	do
	{
		printf("%d", p->data);
		p = p->link;
	} while (p != L->head);
	printf("%d->", p->data); //마지막 노드 출력
}

int main()
{
	CListType list = { NULL,0 };

	char name1[] = "KIM";
	char name2[] = "PARK";
	char name3[] = "CHOI";
	insert_first(&list, name1);
	printf("node count=%d\n", list.nodeCount);
	insert_first(&list, name2);
	printf("node count=%d\n", list.nodeCount);
	insert_first(&list, name3);
	printf("node count=%d\n", list.nodeCount);

	ListNode* p = list.head;
	for (int i = 0; i < 10; i++)
	{
		printf("현재 차례 = %s \n", p->data);
		p = p->link;
	}

	return 0;
}