#include <GL/glut.h>

void init()
{
	GLfloat light_position[] = { 1.0,2.0,3.0,1.0 };
	GLfloat light_ambient[] = { 0.0,1.0,0.0,1.0 };
	GLfloat light_diffuse[] = { 1.0,0.0,0.0,1.0 };
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTeapot(0.5);
	glFlush();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (new_w <= new_h)
	{
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)new_h / (GLfloat)new_w, 1.5 * (GLfloat)new_h / (GLfloat)new_w, -10.0, 10.0 );
	}
	else
	{
		glOrtho(-1.5 * (GLfloat)new_w / (GLfloat)new_h, 1.5 * (GLfloat)new_w / (GLfloat)new_h, -1.5, 1.5, -10.0, 10.0 );

	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("20194463_ÀÌµ¿±Ô");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}