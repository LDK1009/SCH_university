#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



/*
	�ۼ���:2023.03.09
	�ۼ���: ��ǻ�ͼ���Ʈ������а� / 20194463 / �̵���
	���α׷���: �����Ҵ��� �̿��� �ܼ����Ḯ��Ʈ
*/

typedef struct studentData {                      // �ؽ�Ʈ ���Ͽ��� �о�� ������ ����ü ����
	int num;									  // �й�
	char name[20];								  // �̸�
	float grade;								  // ����
}StudentData;

typedef struct node                               // ���Ḯ��Ʈ�� ����� ���� ��� ����
{
	StudentData data;							  // �л� ������ ����ü
	node* next;									  // �ڱ� ���� ����ü
}Node;


Node* head;                                        // ���Ḯ��Ʈ Head ( ���� �պκ� ) 

void printLinkedList()                             // ���Ḯ��Ʈ�� ��ȸ�ϸ� �����͸� ����ϴ� �Լ�
{
	Node* pCurNode = head;                         // �Ӹ����� �����ؼ�
	while (pCurNode != NULL)					   // ������ ����������( ������ )	
	{
		printf("%d %s %f\n", pCurNode->data.num, pCurNode->data.name, pCurNode->data.grade); // pCur�� ����Ű�� ����ü�� ������(�й�, �̸�, ����)�� ����Ѵ�.
		pCurNode = pCurNode->next;                 // ��带 ��� �� ���� ��带 ����Ų��.
	}
}

void sortByNumber(Node* root)                      // �й� ������ �����ϴ� �Լ�
{
	StudentData temp;							   //���� ����
	Node* pCompareNode = root;					   //�� ���
	Node* pIndexNode = root;						


	while (pIndexNode->next != NULL)               // ���������� ���������, IndexNode�� ������ �ܼ� �ݺ����� ����, pCompareNode�� �����Ͱ� ���ϸ�, ũ����� ������ ����, �ܼ� �������� ��ġ�� �����ϰ� �������.
	{
		pCompareNode = root;
		while (pCompareNode->next != NULL)		   // ������ ���� ������ ����
		{
			if (pCompareNode->data.num > pCompareNode->next->data.num)	// �� ����� �й��� ���� ����� �й����� ũ�ٸ� ����(�ݺ��ϸ� ũ�Ⱑ ���� �й��� ���� ���� �´�. ��, ���� �й����� ���� �й� ������ ���ĵȴ�.)
			{
				temp = pCompareNode->next->data;
				pCompareNode->next->data = pCompareNode->data;
				pCompareNode->data = temp;
			}

			pCompareNode = pCompareNode->next;	  // ���� ����
		}


		pIndexNode = pIndexNode->next;			 // ���� ����
	}

}

void sortByName(Node* root)                      // �̸����� ����
{
	StudentData temp;
	Node* pCompareNode = root;
	Node* pIndexNode = root;


	while (pIndexNode->next != NULL)			// strcmp �Լ� ���, �� �� ��ȯ ����� �й� �� ���İ� ����
	{
		pCompareNode = root;
		while (pCompareNode->next != NULL)
		{
			if (strcmp(pCompareNode->data.name, pCompareNode->next->data.name) == 1)	// strcmp(str1, str2)�� str1 > str2 �� ��쿡 ����� ��ȯ
			{
				temp = pCompareNode->next->data;
				pCompareNode->next->data = pCompareNode->data;
				pCompareNode->data = temp;
			}

			pCompareNode = pCompareNode->next;
		}


		pIndexNode = pIndexNode->next;
	}

}

void sortByGrade(Node* root)                    // �й����� ����
{
	StudentData temp;
	Node* pCompareNode = root;
	Node* pIndexNode = root;


	while (pIndexNode->next != NULL)			// �� �� ��ȯ ����� �й� �� ���İ� ����
	{
		pCompareNode = root;
		while (pCompareNode->next != NULL)
		{
			if (pCompareNode->data.grade > pCompareNode->next->data.grade)
			{
				temp = pCompareNode->next->data;
				pCompareNode->next->data = pCompareNode->data;
				pCompareNode->data = temp;
			}

			pCompareNode = pCompareNode->next;
		}


		pIndexNode = pIndexNode->next;
	}
}
int main(void)
{
	FILE* fp = NULL;							// ���� ������ ����
	fp = fopen("data.txt", "r");				// �б���� �ؽ�Ʈ ���� ����

	if (fp == NULL) {							// ���� ���� ���� �� ���α׷� ����
		return -1;
	}

	StudentData data;							// �л� ������ ����ü ����
	while (EOF != fscanf(fp, "%d %s %f", &data.num, &data.name, &data.grade))    // �����͸� �����ϰ� �б� ���� fscanf�� ���, EOF�� ������ ���� �ǹ��Ѵ�. ���� ������ ������ �д´�.
	{
		Node* newNode = (Node*)malloc(sizeof(Node));                             // ��带 �����Ҵ����� ���� ��
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL)                                                        // ���� ��尡 ����ִٸ�, ����
			head = newNode;

		else
		{                                                                       // �ƴ� ��쿡��, �� ��ġ�� ã�� �� ����
			Node* pCurNode = head;
			while (pCurNode->next != NULL)
			{
				pCurNode = pCurNode->next;
			}
			pCurNode->next = newNode;
		}

	}
	printf("\n===================[�⺻]====================\n");
	printLinkedList();

	sortByNumber(head);
	printf("\n===================[1.�й����� ����]====================\n");
	printLinkedList();

	sortByName(head);
	printf("\n===================[2.�̸����� ����]====================\n");
	printLinkedList();

	sortByGrade(head);
	printf("\n===================[3.�������� ����]====================\n");
	printLinkedList();
	fclose(fp);
	return 0;
}

