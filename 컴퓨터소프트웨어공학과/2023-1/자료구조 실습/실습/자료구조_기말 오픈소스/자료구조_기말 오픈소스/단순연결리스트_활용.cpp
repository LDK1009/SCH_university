#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

// �ܼ� ���� ����Ʈ �ڵ�
typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

typedef struct
{
	ListNode* head;
	int length;
} ListType;

//
void init(ListType* list)
{
	if (list == NULL)
		return;

	list->head = NULL;
	list->length = 0;
}

int get_length(ListType* list)
{
	return list->length;
}

ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;

	// ���� ��ġ
	if (pos < 0)
		return NULL;

	for (int i = 0; i < pos; i++)
	{
		tmp_node = tmp_node->link;
	}
	return tmp_node;
}

// phead : ����Ʈ�� ��� �������� ������
// p: ���� ���
// new_node: ������ ���


void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	if (*phead == NULL) // ���� ����Ʈ�� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) // �����尡 null�� ��쿡 ù���� ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void add(ListType* list, int position, element data)
{
	// �߰��� �ű�  ��� �տ� �ִ� ����� ������
	ListNode* p;

	// ������ġ�� ��ȿ�� �˻�
	if ((position >= 0) && (position <= list->length))
	{
		// �޸� �����Ҵ� �� ��ȿ�� üũ
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL)
		{
			printf("memory allocation faillture \n");
			return;
		}
		node->data = data;

		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}

}

void add_last(ListType* list, element data)
{
	add(list, get_length(list), data);
}

void add_first(ListType* list, element data)
{
	add(list, 0, data);
}

int is_empty(ListType* list)
{
	if (list->head == NULL)
		return TRUE;
	else
		return FALSE;
}

// phead: ��������Ϳ� ���� ������
// p:������ ����� ���� ���
// removed : ������ ���
void removed_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;

	free(removed);
}


void deleteNode(ListType* list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length))
	{
		ListNode* p = get_node_at(list, pos - 1);
		removed_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}

void display(ListType* list)
{
	int i;
	ListNode* node = list->head;

	for (i = 0; i < list->length; i++)
	{
		printf("%d\n", node->data);
		node = node->link;
	}
	printf("\n\n");
}

void clear(ListType* list)
{
	int i;
	ListNode* node = list->head;

	for (i = 0; i < list->length; i++)
	{
		printf("%d", node->data);
		node = node->link;

	}
	printf("\n\n");
}

int search_list(ListType* list, element item)
{
	int nCount = 0;
	ListNode* p;

	p = list->head;

	while (p != NULL)
	{
		if (p->data == item)
			nCount++;
		p = p->link;
	}
	return nCount;
}

void delete_even(ListType* list)
{
	int i;

	for (i = 0; i < list->length; i += 2)
	{
		deleteNode(list, i);
	}
}

element listMax(ListType* list)
{
	int max;
	ListNode* p;
	p = list->head;

	if (p != NULL)
	{
		max = p->data;
		p = p->link;
	}

	while (p != NULL)
	{
		if (max < p->data)
			max = p->data;
		p = p->link;
	}

	return max;
}

element listMin(ListType* list)
{
	int min;
	ListNode* p;
	p = list->head;

	if (p != NULL)
	{
		min = p->data;
		p = p->link;
	}

	while (p != NULL)
	{
		if (min > p->data)
			min = p->data;
		p = p->link;
	}

	return min;
}

void main()
{
	FILE* fp;
	int nTemp;
	int nCount = 0;
	ListType list;

	init(&list);

	fp = fopen("data_LinkedList002-1.txt", "r");
	if (fp == NULL)
	{
		printf("file not open\n");
		return;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &nTemp);

		add_last(&list, nTemp);
	}

	fclose(fp);

	// 1�� ����
	//display(&list);


	// 2�� ����
	//while (1)
	//{
	//	printf("���� �Է��Ͻÿ�.(0:����)");
	//	scanf("%d", &nTemp);
	//	if (nTemp == 0)
	//		break;

	//	nCount = search_list(&list, nTemp);
	//	printf("%d�� ����Ʈ�� %d�� �ֽ��ϴ�. \n", nTemp, nCount);
	//}

	// 3�� ����
	//delete_even(&list);
	//display(&list);


	// 4�� ����
	//nTemp = listMax(&list);
	//printf("�ִ밪�� %d�Դϴ�.\n", nTemp);

	//nTemp = listMin(&list);
	//printf("�ּҰ��� %d�Դϴ�.\n", nTemp);

	clear(&list);
}
