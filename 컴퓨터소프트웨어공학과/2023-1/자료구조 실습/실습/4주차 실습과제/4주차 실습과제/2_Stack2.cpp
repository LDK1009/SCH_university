#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct
{
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return(s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
		return;
	else
		s->stack[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
		exit(1);
	else
		return s->stack[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s))
		exit(1);
	else
		return s->stack[(s->top)];
}

int prec(char op) // 연산자 우선순위 부여
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);

	StackType s;

	init(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];

		switch (ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			//스택에 있는 연산자와 문자열의 연산자 우선순위 파악
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(':	// 왼쪽 괄호는 무조건 스택에 넣는다
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(')
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:	// 피연산자
			printf("%c", ch);
			break;
		}	//end of switch
	}	//  end of while
	while (!is_empty(&s))
		printf("%c", pop(&s));
}
void main()
{
	char buf[1024] = { 0 };
	FILE *fp = fopen("data2_Stack2.txt", "r");

	if (fp == NULL)
		return;

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);
		infix_to_postfix(buf);
		printf("\n");
	}
	fclose(fp);
}