#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode
{
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct LinkedQueueType {
	QueueNode* front;
	QueueNode* rear;
} LinkedQueueType;

void initialize(LinkedQueueType* q)
{
	q->front = q->rear = NULL;

}

int isEmpty(LinkedQueueType* q)
{
	return(q->front == NULL);
}

void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));

	temp->data = data;
	temp->link = NULL;

	if (isEmpty(q))
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->link = temp;
		q->rear = temp;
	}
}

void printQueue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("\n");
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element data;

	if (isEmpty(q))
	{
		printf("queue is empty\n");
	}
	else
	{
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL) // last node dequeued
			q->front = NULL; // reset the front and rear pointer
		free(temp);
		return data;
	}
}

int main()
{
	LinkedQueueType q;

	initialize(&q);

	enqueue(&q, 1);
	printQueue(&q);

	enqueue(&q, 2);
	printQueue(&q);

	enqueue(&q, 3);
	printQueue(&q);


	dequeue(&q);
	printQueue(&q);

	dequeue(&q);
	printQueue(&q);

	dequeue(&q);
	printQueue(&q);

}