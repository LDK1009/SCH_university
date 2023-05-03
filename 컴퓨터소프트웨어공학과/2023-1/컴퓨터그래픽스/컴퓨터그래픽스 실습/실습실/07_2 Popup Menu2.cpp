#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float R = 1.0;
float G = 1.0;
float B = 1.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glColor3f(R, G, B);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();


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
	case 4:
		printf("������ ���������� �����մϴ�.. \n");
		R = 1.0; G = 0.0; B = 0.0;
		glutPostRedisplay();
		break;
	case 5:
		printf("������ �ʷϻ����� �����մϴ�.. \n");
		R = 0.0; G = 1.0; B = 0.0;
		glutPostRedisplay();
		break;

	case 6:
		printf("������ �Ķ������� �����մϴ�.. \n");
		R = 0.0; G = 0.0; B = 1.0;
		glutPostRedisplay();
		break;
	case 99:
		printf("openGL ���α׷��� �����մϴ�. \n");
		exit(0);
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("07_2 popupMenu2");

	int submenu = glutCreateMenu(popupMenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Green", 5);
	glutAddMenuEntry("Blue", 6);

	glutCreateMenu(popupMenu);
	glutAddSubMenu("Triangle Color", submenu);
	glutAddMenuEntry("First", 1);
	glutAddMenuEntry("Second", 2);
	glutAddMenuEntry("Third", 3);
	glutAddMenuEntry("Exit", 99);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}