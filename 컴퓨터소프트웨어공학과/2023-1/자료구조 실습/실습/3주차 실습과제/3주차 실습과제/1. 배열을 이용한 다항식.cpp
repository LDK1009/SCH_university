/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.19
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_DEGREE 100

//1번 문제 배열을 이용한 다항식


typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add(polynomial a, polynomial b)
{
	polynomial c;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = a.degree;
	int degree_b = b.degree;

	if (a.degree > b.degree)
		c.degree = a.degree; // a의 차수가 더 높으면 a 차수 다항식이다.
	else
		c.degree = b.degree;

	while (Apos < a.degree && Bpos < b.degree) {
		if (degree_a > degree_b) {
			c.coef[Cpos++] = a.coef[Apos];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			c.coef[Cpos++] = b.coef[Bpos++];
			degree_b--;
		}
	}
	return c;
}

void print_poly(polynomial p) {
	int i;

	for (i = p.degree; i > 0; i--)
		printf("%3.1fX^%d + ", p.coef[p.degree - i], i);
	printf(" % 3.1f\n", p.coef[p.degree]);
}

int main() {
	polynomial a = { 5,{10, 0,0,0,6,3} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;

	//1. 다항식을 수식 형태로 화면에 출력
	print_poly(a);
	print_poly(b);

	//2. 다항식 더하기
	c = poly_add(a, b);

	//3.다항식 합계 출력
	print_poly(c);

	return 0;
}