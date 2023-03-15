#include <GL/glut.h>
#include <stdlib.h>
/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.15
*/


void display(void)
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.50, 0.25, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.375, 0.0);
	glVertex3f(0.75, 0.375, 0.0);
	glVertex3f(0.50, 0.875, 0.0);
	glEnd();




	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("02_과제_삼각형 두개로 별 그리기");
	init();

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}