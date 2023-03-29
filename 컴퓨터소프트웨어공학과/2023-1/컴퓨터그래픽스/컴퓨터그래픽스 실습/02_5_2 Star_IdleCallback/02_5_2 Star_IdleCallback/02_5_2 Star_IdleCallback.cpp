#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.15
*/

GLint index = 0;
GLfloat Delta = 0.0f;
GLfloat angle = 0;

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	glRotatef(angle, 0, 0, 300);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
	glVertex3f(0.75, 0.375, 0.0);
	glVertex3f(-0.75, 0.375, 0.0);
	glVertex3f(0, -0.75, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.75, -0.375, 0.0);
	glVertex3f(0.75, -0.375, 0.0);
	glVertex3f(0, 0.75, 0.0);
	glEnd();


	glFlush();

	glutSwapBuffers();

}

void idleProcess()
{
	angle += 0.0001;
	if (angle > 360.0)
		angle = 0.0f;
	glutPostRedisplay();

}

void timerProcess(int value)
{
	if (Delta < 2.0f)
	{
		Delta = Delta + 0.01f;

		if (++index >= 8)
		{
			index = 0;
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
	else
	{
		Delta = 0.0f;
	}
	glutPostRedisplay();
	glutTimerFunc(200, timerProcess, 1);
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	float WidthFactor = (float)new_w / 250.0;
	float HeightFactor = (float)new_h / 250.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);

}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0f, 0, 0, 0.0f, 0.0f, 1.0f);
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
	glutReshapeFunc(reshape);
	glutIdleFunc(idleProcess);
	glutMainLoop();

	return 0;
}