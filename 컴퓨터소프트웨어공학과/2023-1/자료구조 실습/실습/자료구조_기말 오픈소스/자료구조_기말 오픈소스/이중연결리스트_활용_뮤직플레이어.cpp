#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

// �ִ�뷮 128MB
#define MAX			128
// �Ѱ��� �뷮 4MB
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
	ListNode* play;		// ���� ��� ���� ��
	ListNode* first;		// ù��° �� (== *head)
	int listSize;				// ���
} PlayList;

void initList(PlayList* list)		// ����Ʈ �ʱ�ȭ �Լ�
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


void printList(PlayList* list)	// ����Ʈ ���
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
		if (isEmpty(list)) {  // ����Ʈ�� ����ִ� ���, ù��
			list->first = node;
			list->play = node;
			node->next = NULL;
			node->previous = NULL;
		}
		else if (list->play->next == NULL) { // ����Ʈ�� ���� ���� ���� �߰�
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
		if (isEmpty(list)) {	// ����Ʈ�� ����ִ� ���
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

void insertMusic(PlayList* list, int  mode)  // mode = NORMAL (����� ����), FIRST (����Ʈ ó��)
{
	ListNode* tempNode;
	tempNode = (ListNode*)malloc(sizeof(ListNode));
	tempNode->singer = (char*)malloc(sizeof(char) * 512);
	tempNode->title = (char*)malloc(sizeof(char) * 512);

	printf("������ ? : ");
	getSinger(tempNode);
	printf("��� ? : ");
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

		// ���� ���� ù��° ���� ���
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
		// ����Ʈ�� ��尡 1�� �ۿ� ���ų�, ���� ù���� ���
		if ((list->listSize == 1) || (list->play == list->first)) {
			printf("���� ������ �̵��� �� �����ϴ�.\n");
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
		// ����Ʈ�� ��尡 1�� �ۿ� ���ų�, ���� ù���� ���
		if ((list->listSize == 1) || (list->play->next == NULL)) {
			printf("���� ������ �̵��� �� �����ϴ�.\n");
			return;
		}
		else {
			list->play = list->play->next;
		}
	}
}


int main()
{
	PlayList list;		// �÷��̸���Ʈ
	char cmd;			// ����� ��ɾ�

	initList(&list);

	do {
		printf("\n\n");
		printf("+ : MP3 ����� ������ �߰�\n");
		printf("s : MP3 ����Ʈ ó���� �߰�\n");
		printf("- : MP3 ����� ����\n");
		printf("p : ������\n");
		printf("n : ������\n");
		printf("f : �뷮 üũ\n");
		printf("e : ����Ʈ ����ִ��� üũ\n");
		printf("q : ����\n");

		// ����Ʈ ���
		printList(&list);

		printf("��ɾ� �Է� : ");
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
				printf("�뷮 : %d\n", list.listSize);
			break;
		case 'e':
		case 'E':
			if (isEmpty(&list))
				printf("iPod is EMPTY!!!\n");
			else
				printf("�뷮 : %d\n", list.listSize);
			break;
		case 'q':
		case 'Q':
			break;
		default:
			printf("��ɾ� ����\n");
		}
	} while (cmd != 'q');
}