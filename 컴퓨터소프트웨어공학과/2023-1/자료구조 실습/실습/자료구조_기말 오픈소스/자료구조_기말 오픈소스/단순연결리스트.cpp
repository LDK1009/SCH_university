#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;	//데이터
	struct ListNode* link;	//링크(self-referecial pointer)
};

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 1. 메모리를 할당 받는다
	p->data = value;	//2. data 값을 저장한다
	p->link = head;	//3. 헤드 포인터값을 복사해둔다
	head = p;	//4.헤드포인터를 변경

	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 1. 메모리 할당


	p->data = value; // 2. data 값 저장
	p->link = pre->link; // 3. pre 뒤에 노드를 p가 포인트함
	pre->link = p;	// 4. pre는 p를 다음 노드로 지정

	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL)
	{
		return NULL;
	}

	removed = head;
	head = removed->link;
	free(removed);

	return head;

}

// pre가 가리키는 노드의 다음 노드를 삭제한다
ListNode* deleteNode(ListNode* head, ListNode* pre)
{
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;

	free(removed);

	return head;

}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("\n");
}

int count_list(ListNode* head)
{
	int n = 0;

	for (ListNode* p = head; p != NULL; p = p->link)
	{
		n++;
	}
	return n;
}

int get_sum(ListNode* head)
{
	int sum = 0;

	for (ListNode* p = head; p != NULL; p = p->link)
	{
		sum += p->data;
	}
	return sum;
}

int search(ListNode* head, int value)
{
	int count = 0;

	for (ListNode* p = head; p != NULL; p = p->link)
	{
		if (value == p->data)
			count++;

	}

	return count;
}

int main()
{
	ListNode* head = NULL;

	int count, data, search_num;

	printf("노드 몇개?");
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		printf("노드?");
		scanf("%d", &data);
		head = insert_first(head, data);
	}

	//문제 1번 출력
	printf("연결 리스트:");
	print_list(head);

	//문제 2번 출력
	//printf("\n\n 연결리스트의 개수: %d\n", count_list(head));

	//문제 3번 출력
	//printf("\n\n 연결리스트의 데이터 합: %d\n", get_sum(head));

	//문제 4번 출력
	//printf("\n 탐색할 값을 입력하시오 :");
	//scanf("%d", &search_num);
	//printf("\n %d는 연결리스트에서 %d번 나타납니다", search_num, search(head, search_num));


	return 0;
}