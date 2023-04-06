#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct
{
    int nNum;
    char name[100];
} QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;

void initialize()
{
    front = rear = 0;
}

int isEmpty()
{
    return (front == rear);
}

int isFull()
{
    return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item)
{
    if (isFull())
    {
        printf("queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

QueueObject deleteq()
{
    if (isEmpty())
    {
        printf("queue is empty\n");
        exit(0);
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

int get_count()
{
    return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void print_queue()
{
    int count = get_count();
    printf("front=%d rear=%d count=%d\n", front, rear, count);

    for (int i = 0; i < count; i++)
    {
        QueueObject temp = deleteq();
        printf("%d|%s\n", temp.nNum, temp.name);
        addq(temp);
    }
}

void main()
{
    FILE* fp;
    int nCount;
    QueueObject temp;
    int i;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("file not found\n");
        exit(0);
    }

    nCount = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%d%s", &temp.nNum, temp.name);
        addq(temp);
        nCount++;
    }

    print_queue();

    fclose(fp);
}
