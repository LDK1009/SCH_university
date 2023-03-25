#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ
void init(StackType* s)
{
	s->top = -1;
}

// ���� ����ִ��� üũ
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// ������ ��ȭ �������� üũ
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

// ���ÿ� �ֱ�
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		printf("stack overflow\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

// ���ÿ��� ����
element pop(StackType* s)
{
	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(0);
	}
	else
		return s->stack[(s->top)--];
}


int check_matching(char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];

		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;

		case')':
		case']':
		case'}':
			if (is_empty(&s)) //���� ��ȣ ���� ������ ��ȣ�� �ִ� ��� ��ȣ ����
				return FALSE;
			else
			{
				open_ch = pop(&s); // ���� ��ȣ�� ������ ��ȣ�� ��ġ���� ���� ���
				if ((open_ch == '(') && ch != ')' || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return FALSE;
				break;
			}
		}
	}

	if (!is_empty(&s)) // ������ ��ȣ ���� ���� ��ȣ�� �ִ� ���, ��ȣ ����
		return FALSE;
	return TRUE;
}

void main()
{
	FILE* fp;
	char buf[1024] = { 0 };
	fp = fopen("data1_Stack1.txt", "r");

	if (fp == NULL)
	{
		return;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);

		if (check_matching(buf) == TRUE)
			printf("��ȣ �˻� ����\n");
		else
			printf("��ȣ �˻� ����\n");
		printf("%s\n", buf);
	}

	fclose(fp);
}
