#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// 20194463 이동규
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

void push_bottom(StackType* s, element item)
{
	if (is_full(s))
		return;
	else
		s->stack[0] = item;
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


element eval(char exp[])
{
	int op1, op2, value, i=0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init(&s);

	for (i = 0; i<len; i++)
	{
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')	//입력이 피연산자이면
		{
			value = ch - '0';
			push(&s, value);
		}
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)	// 연산을 수행하고 스택에 저장
			{
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;

			}
		}
	}	// end of Loop

	return pop(&s);
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

void postfix_to_infix(char exp[])
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
				printf("%c", ch);
				break;
			//스택에 있는 연산자와 문자열의 연산자 우선순위 파악
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
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
	int result, result1;
	char buf[1024] = { 0 };
	FILE* fp = fopen("data4_Stack4.txt", "r");

	if (fp == NULL)
		return;

	while (!feof(fp))
	{
		//fscanf(fp, "%s", buf);
		//infix_to_postfix(buf);
		//printf("중위표기식은 %s\n", buf);
		//eval(buf);
		//printf("후위표기식은 %s\n", buf);
		//result = eval(buf);
		//printf("결과값은 %d \n\n", result);

		fscanf(fp, "%s", buf);
		printf("중위표기식은 ");
		postfix_to_infix(buf);
		printf("\n");
		printf("후위표기식은 ");
		infix_to_postfix(buf);
		printf("\n");
		result = eval(buf);
		printf("결과값은 %d \n\n", result);


		/*fscanf(fp, "%s", buf);
		printf("후위표기식은 %s\n", buf);
		result = eval(buf);
		printf("결과값은 %d \n\n", result);
		*/
	}
	fclose(fp);
}
