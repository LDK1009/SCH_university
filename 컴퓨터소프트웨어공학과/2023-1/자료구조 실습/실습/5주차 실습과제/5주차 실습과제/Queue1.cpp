#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;
element queue[MAX_QUEUE_SIZE];
int front, rear;

void initialize()
{
	//원형 큐의 초기화 front, rear = 0
	//선형 큐의 초기화 front, rear = -1

	front = rear = 0;
}

int isEmpty()
{
	return (front == rear);
}

int isFull()
{
	// rear+1 에서 +1은 원형큐에서 항상 비워두는 한칸을 스킵하는 절차
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

int addq(element item)
{
	if (isFull())
	{
		printf("queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

element deleteq()
{
	if (isEmpty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void main()
{
	FILE* fp;
	int temp;
	int i, nCount;

	fp = fopen("data_Queue1.txt", "r");

	if (fp == NULL)
	{
		printf("file open error \n");
		exit(0);
	}

	nCount = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		addq(temp);
		nCount++;

		printf("front=%d rear=%d\n", front, rear);
	}

	for (i = 0; i < nCount; i++)
	{
		printf("deleteq()=%d\n", deleteq());
	}

	printf("front=%d rear=%d\n", deleteq());

	fclose(fp);
}