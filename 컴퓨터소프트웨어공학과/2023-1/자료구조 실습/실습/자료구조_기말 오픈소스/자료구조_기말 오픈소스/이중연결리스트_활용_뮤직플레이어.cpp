#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

// 최대용량 128MB
#define MAX			128
// 한곡의 용량 4MB
#define SONGSIZE	4

#define TRUE		1
#define FALSE		0

#define NORMAL	0
#define FIRST			1

typedef struct ListNode {
	char* title;
	char* singer;
	struct ListNode* next;
	struct ListNode* previous;
} ListNode;

typedef struct PlayList {
	ListNode* play;		// 현재 재생 중인 곡
	ListNode* first;		// 첫번째 곡 (== *head)
	int listSize;				// 곡수
} PlayList;

void initList(PlayList* list)		// 리스트 초기화 함수
{
	printf("list init completed.\n");
	list->first = NULL;
	list->play = NULL;
	list->listSize = 0;
}

int isEmpty(PlayList* list)
{
	if (list->listSize == 0)
		return TRUE;
	else
		return FALSE;
}


void printList(PlayList* list)	// 리스트 출력
{
	ListNode* temp;
	temp = list->first;
	int no = 1;

	if (isEmpty(list)) {
		printf("Playlist is empty!\n");
		return;
	}
	else {
		printf("NOW PLAYING : %s / %s\n", list->play->singer, list->play->title);

		do {
			printf("-------------------------------------\n");
			printf("%d / %s / %s\n", no, temp->singer, temp->title);
			temp = temp->next;
			no++;
		} while (temp != NULL);
		printf("-------------------------------------\n");
	}
}


int isFull(PlayList* list)
{
	if (list->listSize * SONGSIZE >= MAX)
		return TRUE;
	else
		return FALSE;
}
void insertMusicSub(PlayList* list, ListNode* node)
{
	if (isFull(list)) {
		printf("iPod is full!!\n");
		return;
	}
	else {
		if (isEmpty(list)) {  // 리스트가 비어있는 경우, 첫곡
			list->first = node;
			list->play = node;
			node->next = NULL;
			node->previous = NULL;
		}
		else if (list->play->next == NULL) { // 리스트의 가장 끝에 곡을 추가
			node->next = NULL;
			node->previous = list->play;
			list->play->next = node;
			// list->play = list->play->next;
		}
		else {
			node->next = list->play->next;
			list->play->next->previous = node;
			list->play->next = node;
			node->previous = list->play;
			// list->play = list->play->next;
		} // end of else
		list->listSize++;
	} // end of else
}

void insertMusicFirstSub(PlayList* list, ListNode* node)
{
	if (isFull(list)) {
		printf("iPod is full!\n");
		return;
	}
	else {
		if (isEmpty(list)) {	// 리스트가 비어있는 경우
			list->first = node;
			list->play = node;
			node->next = NULL;
			node->previous = NULL;
		}
		else {
			list->first->previous = node;
			node->next = list->first;
			node->previous = NULL;
			list->first = node;
		}
		list->listSize++;
	}
}

void getSinger(ListNode* list) {
	printf("%c", list->singer);
}

void getTitle(ListNode* list) {
	printf("%c", list->title);
}

void insertMusic(PlayList* list, int  mode)  // mode = NORMAL (현재곡 다음), FIRST (리스트 처음)
{
	ListNode* tempNode;
	tempNode = (ListNode*)malloc(sizeof(ListNode));
	tempNode->singer = (char*)malloc(sizeof(char) * 512);
	tempNode->title = (char*)malloc(sizeof(char) * 512);

	printf("가수명 ? : ");
	getSinger(tempNode);
	printf("곡명 ? : ");
	getTitle(tempNode);

	if (mode == NORMAL)
		insertMusicSub(list, tempNode);
	else if (mode == FIRST)
		insertMusicFirstSub(list, tempNode);
}



void deleteMusic(PlayList* list)
{
	if (isEmpty(list)) {
		printf("Playlist is empty! Can't delete current song.\n");
		return;
	}
	else {
		ListNode* current = list->play;

		// 현재 곡이 첫번째 곡인 경우
		if (current == list->first) {
			list->first = current->next;
			if (list->first != NULL)
				list->first->previous = NULL;
			list->play = list->first;
		}
		else {
			current->previous->next = current->next;
			if (current->next != NULL)
				current->next->previous = current->previous;
			list->play = current->next;
		}

		free(current->singer);
		free(current->title);
		free(current);

		list->listSize--;

		printf("Current song deleted.\n");
	}
}

void movePrev(PlayList* list)
{
	if (isEmpty(list)) {
		printf("Playlist is empty! Can't move previous\n");
		return;
	}
	else {
		// 리스트에 노드가 1개 밖에 없거나, 가장 첫곡인 경우
		if ((list->listSize == 1) || (list->play == list->first)) {
			printf("이전 곡으로 이동할 수 없습니다.\n");
			return;
		}
		else {
			list->play = list->play->previous;
		}
	}
}

void moveNext(PlayList* list)
{
	if (isEmpty(list)) {
		printf("Playlist is empty! Can't move next\n");
		return;
	}
	else {
		// 리스트에 노드가 1개 밖에 없거나, 가장 첫곡인 경우
		if ((list->listSize == 1) || (list->play->next == NULL)) {
			printf("다음 곡으로 이동할 수 없습니다.\n");
			return;
		}
		else {
			list->play = list->play->next;
		}
	}
}


int main()
{
	PlayList list;		// 플레이리스트
	char cmd;			// 사용자 명령어

	initList(&list);

	do {
		printf("\n\n");
		printf("+ : MP3 현재곡 다음에 추가\n");
		printf("s : MP3 리스트 처음에 추가\n");
		printf("- : MP3 현재곡 삭제\n");
		printf("p : 이전곡\n");
		printf("n : 다음곡\n");
		printf("f : 용량 체크\n");
		printf("e : 리스트 비어있는지 체크\n");
		printf("q : 종료\n");

		// 리스트 출력
		printList(&list);

		printf("명령어 입력 : ");
		cmd = getchar();
		getchar();	// newline handling

		switch (cmd) {
		case '+':
			insertMusic(&list, NORMAL);
			break;
		case '-':
			deleteMusic(&list);
			break;
		case 's':
		case 'S':
			insertMusic(&list, FIRST);
			break;
		case 'p':
		case 'P':
			movePrev(&list);
			break;
		case 'n':
		case 'N':
			moveNext(&list);
			break;
		case 'f':
		case 'F':
			if (isFull(&list))
				printf("iPod is FULL!!!\n");
			else
				printf("용량 : %d\n", list.listSize);
			break;
		case 'e':
		case 'E':
			if (isEmpty(&list))
				printf("iPod is EMPTY!!!\n");
			else
				printf("용량 : %d\n", list.listSize);
			break;
		case 'q':
		case 'Q':
			break;
		default:
			printf("명령어 오류\n");
		}
	} while (cmd != 'q');
}