#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int year = 0;
int day = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0, 0.0, 0.0);
	glFlush();
}


void popupMenu(int value)
{
	switch (value)
	{
	case 1:
		glutSetWindowTitle("ù��° �޴�");
		printf("ù��° �޴��� �����Ͽ����ϴ�. \n");
		break;
	case 2:
		glutSetWindowTitle("�ι�° �޴�");
		printf("�ι�° �޴��� �����Ͽ����ϴ�. \n");
		break;

	case 3:
		glutSetWindowTitle("����° �޴�");
		printf("����° �޴��� �����Ͽ����ϴ�. \n");
		break;
	case 99:
		printf("openGL ���α׷��� �����մϴ�. \n");
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("07_1 popupMenu");

	glutCreateMenu(popupMenu);
	glutAddMenuEntry("First", 1);
	glutAddMenuEntry("Second", 2);
	glutAddMenuEntry("Third", 3);
	glutAddMenuEntry("Exit", 99);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}