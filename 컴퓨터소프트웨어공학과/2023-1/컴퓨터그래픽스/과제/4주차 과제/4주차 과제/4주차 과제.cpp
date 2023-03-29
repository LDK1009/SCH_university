#include <GL/glut.h> // OpenGL 라이브러리 헤더 파일
#include <iostream>
using namespace std;


/*
과목명 : 컴퓨터그래픽스
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.29
*/


// 키보드 입력 중이 아닐 때 도형을 그리지 않기 위해 변수 생성
bool draw_1_circle = false, draw_2_circle = false, draw_3_star = false, draw_enter_all=false; 

// init 함수
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
// end of init 함수

// reshape 함수
void reshape(int new_w, int new_h)
{
    glViewport(0, 0, new_w, new_h);
    float WidthFactor = (float)new_w / 250.0;
    float HeightFactor = (float)new_h / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);
}
// end of reshape 함수

// 터키 국기 그리기 함수




// 큰 원 그리기 함수
void drawWhiteCircle(float size)
{
    glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);    // 큰원 그리기(반지름 0.5)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(size * cos(radian), size * sin(radian));
    }
    glEnd();
    glutSwapBuffers();

}
// end of 큰 원 그리기 함수

// 작은 원 그리기 함수
void drawRedCircle(float size) {
    glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0); // 색상 설정
    glBegin(GL_POLYGON);    // 작은 원 그리기(반지름 0.1)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(size * cos(radian), size * sin(radian)); // 원 위의 점 추가
    }
    glEnd();
    glutSwapBuffers();
}
// end of 작은 원 그리기 함수

// 별 그리기 함수
void drawStar()
{
    glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);    // 별 그리기
    glVertex3f(0.375, 0.1875, 0.0);
    glVertex3f(-0.375, 0.1875, 0.0);
    glVertex3f(0, -0.375, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.375, -0.1875, 0.0);
    glVertex3f(0.375, -0.1875, 0.0);
    glVertex3f(0, 0.375, 0.0);
    glEnd();
    glutSwapBuffers();

}
// end of 별 그리기 함수

// 모든 도형 그리기 함수
void drawAll()
{
    glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
    // 큰 원 그리기
    glLoadIdentity();
    glTranslatef(-0.5, 0.5, 0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);    // 큰원 그리기(반지름 0.5)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(0.5 * cos(radian), 0.5 * sin(radian));
    }
    glEnd();

    // 작은 원 그리기
    glLoadIdentity();
    glTranslatef(0.5, 0.5, 0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0); // 색상 설정
    glBegin(GL_POLYGON);    // 작은 원 그리기(반지름 0.1)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(0.2 * cos(radian), 0.2 * sin(radian)); // 원 위의 점 추가
    }
    glEnd();

    // 별 그리기
    glLoadIdentity();
    glTranslatef(0, -0.5, 0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);    // 별 그리기
    glVertex3f(0.375, 0.1875, 0.0);
    glVertex3f(-0.375, 0.1875, 0.0);
    glVertex3f(0, -0.375, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.375, -0.1875, 0.0);
    glVertex3f(0.375, -0.1875, 0.0);
    glVertex3f(0, 0.375, 0.0);
    glEnd();


    glutSwapBuffers();
}
// end of 모든 도형 그리기 함수

// 디스플레이 함수
void display()
{
    if (draw_1_circle) 
    {
        drawWhiteCircle(0.5);
    }
    // 키보드 2입력 시 작은 원 그리기 (빨간색)
    if (draw_2_circle) 
    {
        drawRedCircle(0.2);
    }
    // 키보드 3입력 시 별 그리기 (흰색)
    if (draw_3_star) 
    {
        drawStar();
    }
    // 키보드 엔터 입력 시 모든 도형 그리기
    if (draw_enter_all) 
    {
        drawAll();
    }

}
// end of 디스플레이 함수


// 키보드 콜백 함수
void keyboard(unsigned char key, int x, int y)
{
    if (key == '1') // 키패드 1 입력 시
    {
        draw_1_circle = true; // 큰 원 그리기 플래그를 true로 설정
        glutPostRedisplay(); // display 함수 호출하여 다시 그리기

    }

    if (key == '2') // 키패드 2 입력 시
    {
        draw_2_circle = true; // 작은 원 그리기 플래그를 true로 설정
        glutPostRedisplay(); // display 함수 호출하여 다시 그리기

    }

    if (key == '3') // 키패드 3 입력 시
    {
        draw_3_star = true; // 별 그리기 플래그를 true로 설정
        glutPostRedisplay(); // display 함수 호출하여 다시 그리기

    }

    if (key == 13) // 키패드 엔터 입력 시
    {
        draw_enter_all = true; // 모든 도형 그리기 플래그를 true로 설정
        glutPostRedisplay(); // display 함수 호출하여 다시 그리기

    }
}
// end of 키보드 콜백 함수


// 메인 함수
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // GLUT 초기화
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 디스플레이 모드 설정
    glutInitWindowSize(600, 400); // 윈도우 크기 설정
    glutInitWindowPosition(100, 100);   // 윈도우 위치 설정
    glutCreateWindow("4주차 과제_터키 국기 그리기"); // 윈도우 생성
    init();


    glutDisplayFunc(display); // 디스플레이 콜백 함수 등록
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // 키보드 콜백 함수 등록


    glutMainLoop(); // GLUT 메인 루프 실행

    return 0;
}
// end of 메인 함수