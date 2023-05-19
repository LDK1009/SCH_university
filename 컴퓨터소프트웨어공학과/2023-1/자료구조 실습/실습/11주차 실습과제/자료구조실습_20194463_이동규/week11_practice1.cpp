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
		// node->link = NULL �� �ܼ� ���� ����Ʈ head -> node -> NULL ���
		node->link = head; // ���� ����Ʈ�� Ű ����Ʈ! ��嵵 ��带 ����Ʈ ��嵵 ���� ����Ʈ head<->node ���ó�� ����
	}

	else  //head->20->30
	{
		node->link = head->link; 
		head->link = node;
		head = node; // ��������͸� ������ ���� ����
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
		// node->link = NULL �� �ܼ� ���� ����Ʈ head -> node -> NULL ���
		node->link = head; // ���� ť�� Ű ����Ʈ! ��嵵 ��带 ����Ʈ ��嵵 ���� ����Ʈ head<->node ���ó�� ����
	}

	else
	{
		node->link = head->link;  // �ű� ����� ��ũ�� ���� ��� ��忡 �����Ѵ� ��, �ű� ��尡 ���� ��� ��� �տ� �´�  * head->link�� ������ 1�� ��� ������
		head->link = node;		// head<->node ����
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
	printf("%d->", p->data); //������ ��� ���
}

int main()
{
	// ���� ����Ʈ���� ��� �����ʹ� �׻� ������ ��带 ����Ų��
	ListNode* head = NULL; 
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	// circular list = 10->20->30->40

	print_list(head);

	return 0;
}