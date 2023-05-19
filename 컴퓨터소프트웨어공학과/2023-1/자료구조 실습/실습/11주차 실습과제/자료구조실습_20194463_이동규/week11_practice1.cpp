#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_last(ListNode* head, element data )
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	// memory allocation check routine

	node->data = data;

	if (head == NULL)
	{
		head = node;
		// node->link = NULL 은 단순 연결 리스트 head -> node -> NULL 모양
		node->link = head; // 원형 리스트의 키 포인트! 헤드도 노드를 포인트 노드도 나를 포인트 head<->node 모양처럼 구현
	}

	else  //head->20->30
	{
		node->link = head->link; 
		head->link = node;
		head = node; // 헤드포인터를 마지막 노드로 설정
	}

	return head;

}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	// memory allocation check routine

	node->data = data;

	if (head == NULL)
	{
		head = node;
		// node->link = NULL 은 단순 연결 리스트 head -> node -> NULL 모양
		node->link = head; // 원형 큐의 키 포인트! 헤드도 노드를 포인트 노드도 나를 포인트 head<->node 모양처럼 구현
	}

	else
	{
		node->link = head->link;  // 신규 노드의 링크를 기존 헤드 노드에 연결한다 즉, 신규 노드가 기존 헤드 노드 앞에 온다  * head->link는 기존의 1번 노드 포인터
		head->link = node;		// head<->node 구현
	}

	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL)
	{
		return;
	}

	p = head->link;

	do
	{
		printf("%d", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); //마지막 노드 출력
}

int main()
{
	// 원형 리스트에서 헤드 포인터는 항상 마지막 노드를 가리킨다
	ListNode* head = NULL; 
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	// circular list = 10->20->30->40

	print_list(head);

	return 0;
}