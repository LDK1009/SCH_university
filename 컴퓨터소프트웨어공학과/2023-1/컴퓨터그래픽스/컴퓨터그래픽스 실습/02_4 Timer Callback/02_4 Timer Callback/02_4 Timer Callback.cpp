#include<stdio.h>
#include <GL/glut.h>


/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.15
*/

#include <GL/glut.h>

GLfloat Red = 0.0f;
GLfloat Green = 0.0f;
GLfloat Blue = 0.0f;

GLint index = 0;
GLfloat Delta = 0.0f;
unsigned char PALETTE[9][3] =
{
	{255,255,255},
	{0,255,255},
	{255,0,255},
	{192,192,192},
	{128,128,128},
	{128,0,0},
	{0,128,0},
	{0,0,128},
	{0,0,0},
};

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

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	Red = PALETTE[index][0] / 255.0f;
	Green = PALETTE[index][1] / 255.0f;
	Blue = PALETTE[index][2] / 255.0f;

	glColor3f(Red, Green, Blue);

	glBegin(GL_POLYGON);
	glVertex3f(-0.75, -0.75, 0.0);
	glVertex3f(0.75, -0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(-0.75, 0.75, 0.0);
	glEnd();

	glFlush();

	glutSwapBuffers();

}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
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


int main(int argc, char** argv)
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("02_4 Timer Callback");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(200, timerProcess, 1);
	glutMainLoop();

	return 0;
}