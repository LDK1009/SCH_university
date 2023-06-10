#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isEmpty(LinkedStackType* s)
{
	return (s->top == NULL);
}

void push(LinkedStackType* s, element data)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

	if (temp == NULL) {
		printf("memory allocation failed.\n");
	}
	else {
		temp->data = data;
		temp->link = s->top;
		s->top = temp;
	}
}

int pop(LinkedStackType* s)
{
	if (isEmpty(s)) {
		printf("stack is empty\n");
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = (s->top)->link;
		free(temp);
		return data;
	}
}

int peek(LinkedStackType* s)
{
	if (isEmpty(s)) {
		printf("stack is empty\n");
	}
	else {
		return (s->top)->data;
	}
}

void printStack(LinkedStackType* s)
{
	StackNode* temp = s->top;

	for (; temp; temp = temp->link) {
		printf("|(%3d)|\n", temp->data);
	}
	printf("---------\n\n");
}

void clear(LinkedStackType* s)
{
	StackNode* temp = s->top;
	StackNode* removed;

	while (temp) {
		removed = temp;
		temp = temp->link;
		printf("removed->data = %d\n", removed->data);
		free(removed);
	}

	s->top = temp;
}

int prec(int op)
{
	switch (op) {
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
void infix_to_postfix(char exp[], char* inpost)
{
	LinkedStackType s;

	int len = strlen(exp);
	char ch, top_op;
	int i;
	int cnt = 0;
	initialize(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {
				inpost[cnt++] = pop(&s);
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				inpost[cnt++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:		// �ǿ�����
			inpost[cnt++] = ch;
			break;
		}	// end of switch
	}		// end of for

	while (!isEmpty(&s)) {
		inpost[cnt++] = pop(&s);
	}
}

int eval(char exp[])
{
	LinkedStackType s;
	int op1, op2, value, i = 0;
	int len = strlen(exp);

	char ch;

	initialize(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // �ǿ����ڸ�
			value = ch - '0';
			push(&s, value);
		}
		else {
			// �������� ��� �ʿ��� �ǿ����� 2�� pop()
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}	// end of switch
		}	// end of else
	}	// end of for

	return pop(&s);
}

int main()
{
	char buf[] = "(2+3)*4+9";
	char buf2[1024] = { 0 };

	printf("����ǥ��� : %s\n", buf);

	infix_to_postfix(buf, buf2);
	printf("����ǥ��� : %s\n", buf2);

	printf("����ǥ��� ��� : %d\n", eval(buf2));

}