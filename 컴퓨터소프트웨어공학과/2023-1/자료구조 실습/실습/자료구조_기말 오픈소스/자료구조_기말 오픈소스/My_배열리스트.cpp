#include<stdio.h>
#include <stdlib.h>
#include <string>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void init(ArrayListType* L)
{
	L->size = 0;
}

int isEmpty(ArrayListType* L) {
	return L->size == 0;
}

int isFull(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element getItem(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
	{
		printf("위치 오류");
	}
	return L->array[pos];
}

void printList(ArrayListType* L)
{
	int i;
	for (int i = 0; i < L->size; i++)
	{
		printf("%d -> ", L->array[i]);

	}
	printf("\n");
}

void insertList(ArrayListType* L, int pos, element item)
{
	if (!isFull(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

element deleteList(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size) {
		printf("위치 오류");
	}
	item = L->array[pos];
	for (int i = 0; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
}

int main()
{
	ArrayListType list;

	init(&list);
	insertList(&list, 0, 10);
	insertList(&list, 1, 20);
	insertList(&list, 2, 30);
	insertList(&list, 3, 40);
	insertList(&list, 4, 50);
	printList(&list);
	deleteList(&list, 4);
	printList(&list);
}