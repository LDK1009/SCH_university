#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <gl\glut.h>

typedef struct
{
	double** vPoint;
	int** fPoint;

	int vNum;
	int fNum;

}Model;

Model global_model1;

GLfloat lightPosition[4] = { 1.0, 2.0, 0.0, 1.0 };
GLfloat ambientLight[4] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat diffuseLight[4] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat specular[4] = { 1, 1, 1, 1 };

void rendering(Model model)
{
	//�� �׸���
	glPointSize(5);
	glColor3f(0.9, 0.0, 0);
	glBegin(GL_POINTS); {
		for (int i = 0; i < model.vNum; i++)
			glVertex3f(model.vPoint[i][0], model.vPoint[i][1], model.vPoint[i][2]);
	}glEnd();

	//�� �׸���	
	glColor3f(0.5, 0.5, 0.5);

	for (int i = 0; i < model.fNum; i++)
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(model.vPoint[model.fPoint[i][0]][0], model.vPoint[model.fPoint[i][0]][1], model.vPoint[model.fPoint[i][0]][2]);
		glVertex3f(model.vPoint[model.fPoint[i][1]][0], model.vPoint[model.fPoint[i][1]][1], model.vPoint[model.fPoint[i][1]][2]);
		glVertex3f(model.vPoint[model.fPoint[i][2]][0], model.vPoint[model.fPoint[i][2]][1], model.vPoint[model.fPoint[i][2]][2]);
		glEnd();
	}

	//�� �׸���
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);

	for (int i = 0; i < model.fNum; i++) {
		glBegin(GL_LINES);
		glVertex3f(model.vPoint[model.fPoint[i][0]][0], model.vPoint[model.fPoint[i][0]][1], model.vPoint[model.fPoint[i][0]][2]);
		glVertex3f(model.vPoint[model.fPoint[i][1]][0], model.vPoint[model.fPoint[i][1]][1], model.vPoint[model.fPoint[i][1]][2]);

		glVertex3f(model.vPoint[model.fPoint[i][1]][0], model.vPoint[model.fPoint[i][1]][1], model.vPoint[model.fPoint[i][1]][2]);
		glVertex3f(model.vPoint[model.fPoint[i][2]][0], model.vPoint[model.fPoint[i][2]][1], model.vPoint[model.fPoint[i][2]][2]);

		glVertex3f(model.vPoint[model.fPoint[i][2]][0], model.vPoint[model.fPoint[i][2]][1], model.vPoint[model.fPoint[i][2]][2]);
		glVertex3f(model.vPoint[model.fPoint[i][0]][0], model.vPoint[model.fPoint[i][0]][1], model.vPoint[model.fPoint[i][0]][2]);
		glEnd();
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // ���� ����, ���� ���� �ʱ�ȭ
	glShadeModel(GL_SMOOTH);							  // ���� ��� ����(���ν��̵�)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_CCW);

	gluLookAt(0.0, 1.5, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	{
		rendering(global_model1);

		glPopMatrix();
	};
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
}


Model ObjLoad(const char* name) {
	Model model;

	model.vNum = 0;
	model.fNum = 0;

	char c[20];
	int tmp;
	int vCount = 0;
	int fCount = 0;
	int vnCount = 0;

	FILE* fp = fopen(name, "r");

	while (!feof(fp)) {
		fscanf(fp, "%s", &c);
		if (strcmp(c, "v") == 0)
			model.vNum++;
		else if (strcmp(c, "f") == 0)
			model.fNum++;

	}
	rewind(fp);

	model.vPoint = (double**)malloc(sizeof(double*) * model.vNum);
	for (int i = 0; i < model.vNum; i++)
		model.vPoint[i] = (double*)malloc(sizeof(double) * 3);

	model.fPoint = (int**)malloc(sizeof(int*) * model.fNum);
	for (int i = 0; i < model.fNum; i++)
		model.fPoint[i] = (int*)malloc(sizeof(double) * 3);

	while (!feof(fp)) {
		fscanf(fp, "%s", &c);

		if (strcmp(c, "v") == 0) {
			fscanf(fp, "%lf %lf %lf", &model.vPoint[vCount][0], &model.vPoint[vCount][1], &model.vPoint[vCount][2]);
			vCount++;
		}
		else if (strcmp(c, "f") == 0) {
			if (fCount >= model.fNum) break;
			fscanf(fp, "%d %d %d", &model.fPoint[fCount][0], &model.fPoint[fCount][1], &model.fPoint[fCount][2]);
			model.fPoint[fCount][0]--;
			model.fPoint[fCount][1]--;
			model.fPoint[fCount][2]--;
			fCount++;
		}
	}
	printf("MODEL �ε� ���� : %d %d\n", model.vNum, model.fNum);
	return model;
}

void init()
{
	global_model1 = ObjLoad("box.obj");

	glClearColor(1.0, 1.0, 1.0, 0);         // ���� ����	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);          // ���̸� ǥ���ϱ� ���� ����

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);   // �ֺ� �� ���� ����
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);      // �߻� �� ���� ����
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);      // �ݻ� �� ���� ����
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);   // ���� ��ġ ����(����)

	glEnable(GL_LIGHTING);             // ���� �ѱ�
	glEnable(GL_LIGHT0);             // 0�� ���� ���	
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1.5, 1.5, -1.5, 1.5, 1.0, 50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("09_1 OBJ VIEWER");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	for (int i = 0; i < global_model1.vNum; i++)
		free(global_model1.vPoint[i]);
	free(global_model1.vPoint);

	for (int i = 0; i < global_model1.fNum; i++)
		free(global_model1.fPoint[i]);
	free(global_model1.fPoint);
	return 0;
}

