#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include<stdlib.h>
#define NUMBER_SUBJECT 3				//과목 수
#define MAX_NAMELENGH 10				//이름 최대 길이

using namespace std;

typedef struct element					// 입력받을 데이터를 위한 구조체 정의
{
	int id;
	char name[MAX_NAMELENGH];
	int korScore;
	int engScore;
	int mathScore;
	int totalScore;
	float avgScore;
}element;

typedef struct ListNode					//단일 연결리스트 
{
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//새 노드 할당

	node->data = data;

	if (head == NULL)                                           // head에 내용이 없다면 먼저 채워준다.
	{
		head = node;

		node->link = head;										// 새 데이터의 link에 head가 대입 ( 원형 리스트의 키 포인트! 헤드도 노드를 포인트 노드도 나를 포인트 head<->node 모양처럼 구현 )
	}

	else                                                        // 이외의 경우, 기존 데이터에 연결
	{
		node->link = head->link;                                // 새 노드의 link를 head->link를 넣어주고,
		head->link = node;                                      // head가 새로 생긴 노드를 link 로 가리키게 한다. 
		head = node;                                            // 그 다음 head를 바꿔준다. ( 헤드가 마지막 노드가 됨 )
	}

	return head;

}

void print_list(ListNode* head)
{
	ListNode* p = nullptr;

	printf(":========:======:====:====:====:====:======:\n");
	printf(":  학번  : 이름 :국어:영어:수학:총점: 평균 :\n");
	printf(":========:======:====:====:====:====:======:\n");

	if (head == NULL)
	{
		printf(":========:======:====:====:====:====:======:\n");
		return;
	}


	p = head->link; // head 다음 노드( 사실상 첫 노드 )부터 헤드가 head가 아닐때까지 반복, 즉 나왔을때는 head 노드를 가리키고 있으므로 한번 더 출력
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
	printf(":  학번  : 이름 :국어:영어:수학:총점: 평균 :\n");
	printf(":========:======:====:====:====:====:======:\n");

	if (head == NULL)
	{
		printf(":========:======:====:====:====:====:======:\n");
		return;
	}


	p = head->link;

	int maxScore = 0;
	element maxData;
	do       // 최대 점수를 가진 노드 maxData에 삽입
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
	while (in >> el.id >> el.name >> el.korScore >> el.engScore >> el.mathScore)  // 파일에 들어가있는 데이터 형식 에 따라 읽어 들인다.
	{
		el.totalScore = el.korScore + el.engScore + el.mathScore;
		el.avgScore = (float)el.totalScore / NUMBER_SUBJECT;
		head = insert_last(head, el);
	}
	return head;
}

ListNode* delete_list(ListNode* head) // 리스트 삭제
{
	if (head == nullptr)
		return nullptr;

	ListNode* p = nullptr;
	ListNode* temp = nullptr;

	p = head->link;            // 삭제를 위해 삭제할 노드 다음 노드를 가리키는 temp 노드 활용, 현재 노드 지우고 temp노드로 넘어간다
	do
	{
		temp = p->link;
		delete(p);
		p = nullptr;

		p = temp;
	} while (temp != head);

	delete(p);               // head 노드 삭제
	return nullptr;
}

int main()
{
	ListNode* head = NULL;
	head = read_file(head);
	print_list(head);

	printf("\n\n최고점수는?\n");
	print_bestScore(head);

	printf("\n\n삭제된 후 출력\n");
	head = delete_list(head);
	print_list(head);
	return 0;
}