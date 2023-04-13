#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



/*
	작성일:2023.03.09
	작성자: 컴퓨터소프트웨어공학과 / 20194463 / 이동규
	프로그램명: 동적할당을 이용한 단순연결리스트
*/

typedef struct studentData {                      // 텍스트 파일에서 읽어올 데이터 구조체 정의
	int num;									  // 학번
	char name[20];								  // 이름
	float grade;								  // 총점
}StudentData;

typedef struct node                               // 연결리스트를 만들기 위한 노드 정의
{
	StudentData data;							  // 학생 데이터 구조체
	node* next;									  // 자기 참조 구조체
}Node;


Node* head;                                        // 연결리스트 Head ( 제일 앞부분 ) 

void printLinkedList()                             // 연결리스트를 순회하며 데이터를 출력하는 함수
{
	Node* pCurNode = head;                         // 머리부터 시작해서
	while (pCurNode != NULL)					   // 다음이 없을때까지( 끝까지 )	
	{
		printf("%d %s %f\n", pCurNode->data.num, pCurNode->data.name, pCurNode->data.grade); // pCur이 가리키는 구조체의 데이터(학번, 이름, 총점)를 출력한다.
		pCurNode = pCurNode->next;                 // 노드를 출력 후 다음 노드를 가리킨다.
	}
}

void sortByNumber(Node* root)                      // 학번 순으로 정렬하는 함수
{
	StudentData temp;							   //변경 공간
	Node* pCompareNode = root;					   //비교 노드
	Node* pIndexNode = root;						


	while (pIndexNode->next != NULL)               // 버블정렬을 사용했으며, IndexNode의 역할은 단순 반복문을 위함, pCompareNode가 다음것과 비교하며, 크기비교후 데이터 변경, 단순 데이터의 위치만 변경하게 만들었다.
	{
		pCompareNode = root;
		while (pCompareNode->next != NULL)		   // 다음이 없을 때까지 진행
		{
			if (pCompareNode->data.num > pCompareNode->next->data.num)	// 비교 노드의 학번이 다음 노드의 학번보다 크다면 변경(반복하면 크기가 낮은 학번이 가장 위로 온다. 즉, 높은 학번부터 낮은 학번 순으로 정렬된다.)
			{
				temp = pCompareNode->next->data;
				pCompareNode->next->data = pCompareNode->data;
				pCompareNode->data = temp;
			}

			pCompareNode = pCompareNode->next;	  // 다음 진행
		}


		pIndexNode = pIndexNode->next;			 // 다음 진행
	}

}

void sortByName(Node* root)                      // 이름으로 정렬
{
	StudentData temp;
	Node* pCompareNode = root;
	Node* pIndexNode = root;


	while (pIndexNode->next != NULL)			// strcmp 함수 사용, 비교 및 교환 방식은 학번 순 정렬과 동일
	{
		pCompareNode = root;
		while (pCompareNode->next != NULL)
		{
			if (strcmp(pCompareNode->data.name, pCompareNode->next->data.name) == 1)	// strcmp(str1, str2)는 str1 > str2 인 경우에 양수를 반환
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

void sortByGrade(Node* root)                    // 학번으로 정렬
{
	StudentData temp;
	Node* pCompareNode = root;
	Node* pIndexNode = root;


	while (pIndexNode->next != NULL)			// 비교 및 교환 방식은 학번 순 정렬과 동일
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
	FILE* fp = NULL;							// 파일 포인터 선언
	fp = fopen("data.txt", "r");				// 읽기모드로 텍스트 파일 열기

	if (fp == NULL) {							// 파일 열기 실패 시 프로그램 종료
		return -1;
	}

	StudentData data;							// 학생 데이터 구조체 선언
	while (EOF != fscanf(fp, "%d %s %f", &data.num, &data.name, &data.grade))    // 데이터를 간편하게 읽기 위해 fscanf를 사용, EOF는 파일의 끝을 의미한다. 따라서 파일의 끝까지 읽는다.
	{
		Node* newNode = (Node*)malloc(sizeof(Node));                             // 노드를 동적할당으로 생성 후
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL)                                                        // 먼저 헤드가 비어있다면, 삽입
			head = newNode;

		else
		{                                                                       // 아닐 경우에는, 들어갈 위치를 찾은 후 삽입
			Node* pCurNode = head;
			while (pCurNode->next != NULL)
			{
				pCurNode = pCurNode->next;
			}
			pCurNode->next = newNode;
		}

	}
	printf("\n===================[기본]====================\n");
	printLinkedList();

	sortByNumber(head);
	printf("\n===================[1.학번으로 정렬]====================\n");
	printLinkedList();

	sortByName(head);
	printf("\n===================[2.이름으로 정렬]====================\n");
	printLinkedList();

	sortByGrade(head);
	printf("\n===================[3.학점으로 정렬]====================\n");
	printLinkedList();
	fclose(fp);
	return 0;
}

