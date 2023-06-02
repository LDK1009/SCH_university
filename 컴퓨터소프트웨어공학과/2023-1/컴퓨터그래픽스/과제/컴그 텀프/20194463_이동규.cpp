#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define PLANET_NUM 6
#define PLANET_SIZE 0.2


typedef struct {
	float x, y, z;
	float sizeRatio;
	float speedRatio;
	float speed;
	float r, g, b;
}PLANET;                                                       // 행성 구조체로 위치, 크기비율, 속도비율, 속도, 색깔 값을 가진다.

enum TYPE { SUN, MERCURY, VENUS, EARTH, MARS, MOON = 5 };       // 배열에서 그냥 숫자로 넣기엔 특정 행성 구별하기가 힘들기 때문에 enum으로 정의

PLANET planet[PLANET_NUM];

float cameraY, cameraZ;                                // 방향키를 통한 카메라 이동을 위해 쓰이는 카메라 y,z값 변수
float rotateAngle;                                     // 방향키를 통한 카메라 회전을 위한 회전 각도
float planetSpeed = 1.f;                               // +,- 키를 이용한 속도 증감을 위한 변수
bool pause;
void init()                              // 실행 전 데이터들을 셋팅하기 위한 함수
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	srand(time(NULL));					// 랜덤함수를 사용 전에 다양한 값이 나올 수 있도록 시드를 타임으로 설정

	//사이즈 및 속도 비율 설정
	planet[SUN].sizeRatio = 1.f;
	planet[MOON].sizeRatio = 0.06f;
	planet[EARTH].sizeRatio = 0.25f;
	planet[MERCURY].sizeRatio = 0.1f;
	planet[VENUS].sizeRatio = 0.25f;
	planet[MARS].sizeRatio = 0.125;

	planet[SUN].speedRatio = 0.f;
	planet[MOON].speedRatio = 0.07f;
	planet[EARTH].speedRatio = 1.0f;
	planet[MERCURY].speedRatio = 0.25f;
	planet[VENUS].speedRatio = 0.6f;
	planet[MARS].speedRatio = 1.9f;

	//행성 위치 설정
	planet[0].x = 0;
	planet[0].y = -2;
	planet[0].z = -2;

	planet[0].r = 1;
	planet[0].g = 0;
	planet[0].b = 0;

	for (int i = 1; i < PLANET_NUM - 1; ++i)
	{
		planet[i].x = planet[i - 1].x - 0.35f;
		planet[i].y = -2;
		planet[i].z = -2;

		//행성 색깔 설정
		planet[i].r = (rand() % 256) / (float)255;
		planet[i].g = (rand() % 256) / (float)255;
		planet[i].b = (rand() % 256) / (float)255;
	}

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0, cameraY, cameraZ);				// 방향키 입력을 통한 카메라 이동을 객체 위치를 움직여 구현
	glRotatef(rotateAngle, 1.f, 1.5f, 0.f);         // 방향키 입력을 통한 카메라 회전 구현

	for (int i = 0; i < PLANET_NUM - 1; ++i)        // 행성 개수만큼 반복을 돌것이지만, 마지막 행성인 달은 따로 그려줄 것이기 때문에 -1만큼 반복
	{
		glColor3f(planet[i].r, planet[i].g, planet[i].b); // 행성 색깔
		glPushMatrix();
		glRotatef(planet[i].speed, 0.f, 1.f, 1.f);        // 아래와 같이 행성 위치 이동과 회전을 시킴으로써 공전 구현
		glTranslatef(planet[i].x, planet[i].y, planet[i].z);

		if (i == TYPE::EARTH)                              // 지구의 경우, 달이 있다.
		{
			glPushMatrix();
			glRotatef(planet[i].speed, 0.f, 1.f, 1.f);     // 자전 구현
			glutWireSphere(PLANET_SIZE * planet[i].sizeRatio, 20, 20); // 지구 그리기
			glPushMatrix();
			glRotatef(planet[TYPE::MOON].speed, 0.f, 1.f, 1.f);       // 아래와 같이 달 위치 이동과 회전을 시킴으로써 공전 구현
			glTranslatef(-0.15f, 0, 0);
			glutWireSphere(PLANET_SIZE * planet[TYPE::MOON].sizeRatio, 20, 20); // 달 그리기
			glPopMatrix();
			glPopMatrix();
		}
		else
			glutWireSphere(PLANET_SIZE * planet[i].sizeRatio, 20, 20);      // 나머지 행성 그리기
		glPopMatrix();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h, 1.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) // 키보드 입력시 들어오는 함수
{
	static float prevSpeed;
	switch (key)						//더하기버튼 속도 증가, 뺄셈 버튼은 속도 감소
	{
	case '+':
		planetSpeed *= 2;
		break;
	case '-':
		planetSpeed *= 0.5;
		break;
	case ' ':                           // 스페이스바 입력시 일시정지, 재입력시 다시 시작
		if (pause == false)
		{
			prevSpeed = planetSpeed;
			planetSpeed = 0.f;
			pause = true;
		}
		else
		{
			planetSpeed = prevSpeed;
			pause = false;
		}
		break;
	}
	glutPostRedisplay();
}

void spacialkeyboard(int key, int x, int y) // 방향키 등 특수키 입력시 들어오는 함수
{
	static float a = 0, b = 0, c = 0;

	switch (key)
	{
	case GLUT_KEY_LEFT:                     // 좌측 방향키 입력
		rotateAngle += 1;
		break;
	case GLUT_KEY_RIGHT:
		rotateAngle -= 1;
		break;
	case GLUT_KEY_UP:
		cameraY += 0.05f;
		cameraZ += 0.05f;
		break;
	case GLUT_KEY_DOWN:
		cameraY -= 0.05f;
		cameraZ -= 0.05f;
		break;
	case GLUT_KEY_HOME:                     // home 키 입력, 초기화
		cameraY = cameraZ = rotateAngle = 0;
		break;
	}

	glutPostRedisplay();
}


void timerProcess(int value)
{
	for (int i = 0; i < PLANET_NUM; ++i)
	{
		planet[i].speed += planet[i].speedRatio * planetSpeed;      // 이동속도는 행성이 가진 속도 비율에 따라 결정
	}
	glutPostRedisplay();
	glutTimerFunc(10, timerProcess, 1);     // 0.01초 간격으로 반복
}

void MenuFunc(int id)
{
	cameraY = cameraZ = rotateAngle = 0;
	if (id == 1) //Top View 메뉴 클릭시
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
	}
	else if (id == 2) //Side View 메뉴 클릭시
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 1, -5, 0.0, 0.0, -4.0, 0.0, 1.0, 0.0);
	}
	else if (id == 3) //Front View 메뉴 클릭시
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(-5, 1, 0, -3.3, -0.1, -0.6, -5.75, 9.6, 7);
	}
	else if (id == 4) //Random View 메뉴 클릭시
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, -1.5, -6, 0, -2, -1.5, 14, -4.1, -6);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);                     // 윈도우 크기 설정
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System");

	init();
	GLint MyMainMenuID = glutCreateMenu(MenuFunc);    // 메뉴 등록
	glutAddMenuEntry("Top View", 1);                  // 1. 메뉴 Top view
	glutAddMenuEntry("Side View", 2);
	glutAddMenuEntry("Front View", 3);
	glutAddMenuEntry("Random View", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);                // 위에서 정의한 메뉴를 마우스 우클릭에 등록
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(spacialkeyboard);
	glutTimerFunc(200, timerProcess, 1);               // 타이머 함수 등록
	glutMainLoop();

	return 0;

}