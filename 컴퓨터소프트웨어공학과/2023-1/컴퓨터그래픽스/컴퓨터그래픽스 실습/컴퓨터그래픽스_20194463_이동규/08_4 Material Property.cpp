#include <GL/glut.h>
#include <stdlib.h>

void myinit(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//LIGHT0 ���� ���� ����
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	//���� �ֺ��� ����
	glLightfv(GL_LIGHT_MODEL_AMBIENT , lmodel_ambient);
	glLightfv(GL_LIGHT_MODEL_LOCAL_VIEWER , local_view);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearColor(0.0, 0.1, 0.1, 0.0);

}

void display()
{
	//���� ���� ����
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_Shininess[] = { 0.0 };
	GLfloat low_Shininess[] = { 5.0 };
	GLfloat high_Shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//ù��° ��
	//������ diffuse�� �ְ� Ambient, Specularm Shininess, Emission�� ���� ����


	//������ diffuse, Specular�� �ְ� Shininess�� low �̸� Ambient, Emission�� ���� ����

}