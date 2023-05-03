#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int year = 0;
int day = 0;
//Sun
float R = 1.0;
float G = 1.0;
float B = 1.0;
//Moon
float R2 = 1.0;
float G2 = 0.0;
float B2 = 0.0;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �ڵ� �߰�

	glEnable(GL_DEPTH_TEST); // ���� �׽���

	glPushMatrix();
	glColor3f(R, G, B);
	glutSolidSphere(1.0, 20, 16);

	glColor3f(R2, G2, B2);
	glRotatef(year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef(day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.2, 10, 8);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		day = (day + 10) % 360;
		break;
	case 'D':
		day = (day - 10) % 360;
		break;
	case 'y':
		day = (year - 5) % 360;
		break;
	case 'Y':
		day = (year - 5) % 360;
		break;
	default:
		break;
	}
	glutPostRedisplay();
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
		printf("Sun�� ������ ���������� �����մϴ�.. \n");
		R = 1.0; G = 0.0; B = 0.0;
		glutPostRedisplay();
		break;
	case 5:
		printf("Sun�� ������ ��������� �����մϴ�.. \n");
		R = 1.0; G = 1.0; B = 0.0;
		glutPostRedisplay();
		break;
	case 6:
		printf("Moon�� ������ �Ͼ������ �����մϴ�.. \n");
		R2 = 1.0; G2 = 1.0; B2 = 1.0;
		glutPostRedisplay();
		break;
	case 7:
		printf("Moon�� ������ �Ķ������� �����մϴ�.. \n");
		R2 = 0.0; G2 = 0.0; B2 = 1.0;
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // �ڵ� �߰�
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("9���� ����");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	int submenu = glutCreateMenu(popupMenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Yellow", 5);

	int submenu2 = glutCreateMenu(popupMenu);
	glutAddMenuEntry("White", 6);
	glutAddMenuEntry("Blue", 7);

	glutCreateMenu(popupMenu);
	glutAddSubMenu("Sun Color", submenu);
	glutAddSubMenu("Moon Color", submenu2);
	glutAddMenuEntry("First", 1);
	glutAddMenuEntry("Second", 2);
	glutAddMenuEntry("Third", 3);
	glutAddMenuEntry("Exit", 99);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();



	return 0;

}



