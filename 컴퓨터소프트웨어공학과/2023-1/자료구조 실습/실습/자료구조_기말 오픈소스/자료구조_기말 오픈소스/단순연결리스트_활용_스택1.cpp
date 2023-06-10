#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct LinkedStackType {
	struct StackNode* top;
} LinkedStackType;

void initialize(LinkedStackType* s)
{
	s->top = NULL;
}

void push(LinkedStackType* s, element data)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

	if (temp == NULL)
	{
		printf("memory allocation failed \n");
	}
	else
	{
		temp->data = data;
		temp->link = s->top;
		s->top = temp;
	}
}

void clear(LinkedStackType* s)
{
	StackNode* temp = s->top;
	StackNode* removed;

	while (temp)
	{
		removed = temp;
		temp = temp->link;
		printf("removed->data=%d\n", removed->data);
		free(removed);
	}
	s->top = temp;
}

void printStack(LinkedStackType* s)
{
	StackNode* temp = s->top;

	for (; temp; temp = temp->link) { //temp가 null이 아니면 newxtnode로 이동
		printf("|(%3d)|\n", temp->data);
	}
	printf("---------\n");
}

int main()
{
	LinkedStackType s;

	initialize(&s);

	push(&s, 15);
	push(&s, 62);
	push(&s, 35);
	push(&s, 52);
	push(&s, 37);
	push(&s, 55);

	printf("\n--출력--\n");
	printStack(&s);

	printf("\n--클리어--\n");
	clear(&s);


	printf("\n--출력--\n");
	printStack(&s);


}