#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include<stdlib.h>
#define NUMBER_SUBJECT 3				//���� ��
#define MAX_NAMELENGH 10				//�̸� �ִ� ����

using namespace std;

typedef struct element					// �Է¹��� �����͸� ���� ����ü ����
{
	int id;
	char name[MAX_NAMELENGH];
	int korScore;
	int engScore;
	int mathScore;
	int totalScore;
	float avgScore;
}element;

typedef struct ListNode					//���� ���Ḯ��Ʈ 
{
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//�� ��� �Ҵ�

	node->data = data;

	if (head == NULL)                                           // head�� ������ ���ٸ� ���� ä���ش�.
	{
		head = node;

		node->link = head;										// �� �������� link�� head�� ���� ( ���� ����Ʈ�� Ű ����Ʈ! ��嵵 ��带 ����Ʈ ��嵵 ���� ����Ʈ head<->node ���ó�� ���� )
	}

	else                                                        // �̿��� ���, ���� �����Ϳ� ����
	{
		node->link = head->link;                                // �� ����� link�� head->link�� �־��ְ�,
		head->link = node;                                      // head�� ���� ���� ��带 link �� ����Ű�� �Ѵ�. 
		head = node;                                            // �� ���� head�� �ٲ��ش�. ( ��尡 ������ ��尡 �� )
	}

	return head;

}

void print_list(ListNode* head)
{
	ListNode* p = nullptr;

	printf(":========:======:====:====:====:====:======:\n");
	printf(":  �й�  : �̸� :����:����:����:����: ��� :\n");
	printf(":========:======:====:====:====:====:======:\n");

	if (head == NULL)
	{
		printf(":========:======:====:====:====:====:======:\n");
		return;
	}


	p = head->link; // head ���� ���( ��ǻ� ù ��� )���� ��尡 head�� �ƴҶ����� �ݺ�, �� ���������� head ��带 ����Ű�� �����Ƿ� �ѹ� �� ���
	do
	{
		printf(":%d:%s:%4d:%4d:%4d:%4d:%.2f:\n", p->data.id, p->data.name, p->data.korScore, p->data.engScore, p->data.mathScore, p->data.totalScore, p->data.avgScore);
		p = p->link;
	} while (p != head);
	printf(":%d:%s:%4d:%4d:%4d:%4d:%.2f:\n", p->data.id, p->data.name, p->data.korScore, p->data.engScore, p->data.mathScore, p->data.totalScore, p->data.avgScore);
	printf(":========:======:====:====:====:====:======:\n");

}

void print_bestScore(ListNode* head)
{
	ListNode* p = nullptr;

	printf(":========:======:====:====:====:====:======:\n");
	printf(":  �й�  : �̸� :����:����:����:����: ��� :\n");
	printf(":========:======:====:====:====:====:======:\n");

	if (head == NULL)
	{
		printf(":========:======:====:====:====:====:======:\n");
		return;
	}


	p = head->link;

	int maxScore = 0;
	element maxData;
	do       // �ִ� ������ ���� ��� maxData�� ����
	{
		if (maxScore < p->data.totalScore)
		{
			maxScore = p->data.totalScore;
			maxData = p->data;
		}
		p = p->link;
	} while (p != head);

	printf(":%d:%s:%4d:%4d:%4d:%4d:%.2f:\n", maxData.id, maxData.name, maxData.korScore, maxData.engScore, maxData.mathScore, maxData.totalScore, maxData.avgScore);
	printf(":========:======:====:====:====:====:======:\n");


}
ListNode* read_file(ListNode* head)
{
	ifstream in("data.txt");
	if (!in)
	{
		printf("File Open Error\n");
		return nullptr;
	}

	element el;
	while (in >> el.id >> el.name >> el.korScore >> el.engScore >> el.mathScore)  // ���Ͽ� ���ִ� ������ ���� �� ���� �о� ���δ�.
	{
		el.totalScore = el.korScore + el.engScore + el.mathScore;
		el.avgScore = (float)el.totalScore / NUMBER_SUBJECT;
		head = insert_last(head, el);
	}
	return head;
}

ListNode* delete_list(ListNode* head) // ����Ʈ ����
{
	if (head == nullptr)
		return nullptr;

	ListNode* p = nullptr;
	ListNode* temp = nullptr;

	p = head->link;            // ������ ���� ������ ��� ���� ��带 ����Ű�� temp ��� Ȱ��, ���� ��� ����� temp���� �Ѿ��
	do
	{
		temp = p->link;
		delete(p);
		p = nullptr;

		p = temp;
	} while (temp != head);

	delete(p);               // head ��� ����
	return nullptr;
}

int main()
{
	ListNode* head = NULL;
	head = read_file(head);
	print_list(head);

	printf("\n\n�ְ�������?\n");
	print_bestScore(head);

	printf("\n\n������ �� ���\n");
	head = delete_list(head);
	print_list(head);
	return 0;
}