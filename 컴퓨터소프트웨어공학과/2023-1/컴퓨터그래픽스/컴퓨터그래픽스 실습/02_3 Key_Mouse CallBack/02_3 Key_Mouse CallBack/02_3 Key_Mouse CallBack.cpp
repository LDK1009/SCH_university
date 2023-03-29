#include<stdio.h>
#include <GL/glut.h>


/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.15
*/

#include <GL/glut.h>


void display() {
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(-0.75, -0.75, 0.0);
	glVertex3f(0.75, -0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(-0.75, 0.75, 0.0);
	glEnd();

	glFlush();

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

// 키, 마우스 콜백



void keyboardProcess(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case '1':
		printf("숫자 1키를 입력하였습니다.\n");
		break;
	case '2':
		printf("숫자 2키를 입력하였습니다.\n");
		break;
	case '5':
		printf("숫자 5키를 입력하였습니다.\n");
		break;
	case 'Q':
		printf("문자 Q키를 입력하였습니다.\n");
		break;
	}
}
void mouseProcess(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("왼쪽 마우스 버튼을 클릭하였습니다.\n");
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		printf("가운데 마우스 버튼을 클릭하였습니다.\n");
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("오른쪽 마우스 버튼을 클릭하였습니다.\n");
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		printf("왼쪽 마우스 버튼을 뗐습니다.\n");
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
	{
		printf("왼쪽 마우스 버튼을 뗐습니다.\n");
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		printf("왼쪽 마우스 버튼을 뗐습니다.\n");
	}

}
// 키, 마우스 콜백

int main(int argc, char** argv)
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("02 Reshape Callback");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardProcess);
	glutMouseFunc(mouseProcess);
	glutMainLoop();

	return 0;
}