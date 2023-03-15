#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.15
*/


static int delay = 10;

void init()
{
	srand(time(0));
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의배경을지울때사용될색상을지정
	glColor3f(1.0, 0.0, 0.0); // Red, Green, Blue를이용한색상지정
	gluOrtho2D(.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT); // 색상버퍼를지움 / 인수로어떤버퍼를지울것인가를지정/ 두개이상의버퍼를한꺼번에지울수있음
}

void display()
{
	int x1, y1, x2, y2, r, g, b;

	x1 = rand() % 50; y1 = rand() % 50; x2 = rand() % 50; y2 = rand() % 50;
	r = rand() % 256; g = rand() % 256; b = rand() % 256;

	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b / 255);

	glBegin(GL_POLYGON); // 선,점,면 등을 그리기 위해 사용함 / glBegin()과glEnd()의사이에정점정보를넣음
	glVertex2f(x1, y1); glVertex2f(x1, y2); // 정점의x, y, z 좌표설정 / 2f 는 x, y 좌표 설정
	glVertex2f(x2, y2); glVertex2f(x2, y1);
	glEnd();

	glFlush(); // 버퍼에서기다리던명령들을실행
}

void timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(delay, timer, t);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);	// 그래픽을출력할윈도우의크기(너비와높이)를지정
	glutCreateWindow("Prog02: Random boxes"); // 윈도우를 생성 / 윈도우상단의제목을문자열을인수로지정 / 새로운윈도우에대한ID가리턴됨/ glutMainLoop()이호출되기전까지는윈도우가디스플레이되지않음
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0);

	init();
	glutMainLoop();// 윈도우가 디스플레이가 된다 / 무한이벤트처리루프

	return 0;
}
