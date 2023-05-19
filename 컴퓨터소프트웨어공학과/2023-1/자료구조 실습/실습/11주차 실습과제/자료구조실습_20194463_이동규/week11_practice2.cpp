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
		// node->link = NULL �� �ܼ� ���� ����Ʈ head -> node -> NULL ���
		node->link = L->head; // ���� ����Ʈ�� Ű ����Ʈ! ��嵵 ��带 ����Ʈ ��嵵 ���� ����Ʈ head<->node ���ó�� ����
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
		// node->link = NULL �� �ܼ� ���� ����Ʈ head -> node -> NULL ���
		node->link = L->head; // ���� ť�� Ű ����Ʈ! ��嵵 ��带 ����Ʈ ��嵵 ���� ����Ʈ head<->node ���ó�� ����
	}

	else
	{
		node->link = L->head->link;  // �ű� ����� ��ũ�� ���� ��� ��忡 �����Ѵ� ��, �ű� ��尡 ���� ��� ��� �տ� �´�  * head->link�� ������ 1�� ��� ������
		L->head->link = node;		// head<->node ����
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
	printf("%d->", p->data); //������ ��� ���
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
		printf("���� ���� = %s \n", p->data);
		p = p->link;
	}

	return 0;
}