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

/*
프로그램 오류
1. 키보드 콜백 순서에 따른 도형 그리기 오류((1 -> 2 -> 3 -> 엔터) 순으로 입력하면 모든 도형을 그릴 수 있지만 해당 순서를 지키지 않을 시
도형이 그려지지 않는 오류가 발생한다. ex) 3 -> 1 -> 2 -> 엔터 순으로 입력 시 3과 엔터 키보드 입력에만 반응한다.)
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


// 하얀 원 그리기 함수
void drawWhiteCircle(float size)
{
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);    // 큰원 그리기(반지름 0.5)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(size * cos(radian), size * sin(radian));
    }
    glEnd();
}
// end of 큰 원 그리기 함수

// 빨간 원 그리기 함수
void drawRedCircle(float size) {
    glColor3f(1.0, 0.0, 0.0); // 색상 설정
    glBegin(GL_POLYGON);    // 작은 원 그리기(반지름 0.1)
    for (int i = 0; i < 360; i++)
    {
        float radian = i * 3.14 / 180.0;
        glVertex2f(size * cos(radian), size * sin(radian)); // 원 위의 점 추가
    }
    glEnd();
}
// end of 작은 원 그리기 함수

// 별 그리기 함수
void drawStar()
{
    glColor3f(1.0, 1.0, 1.0); // 색상 설정
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.1, 0.0);
    glVertex3f(0.1, -0.16, 0.0);
    glVertex3f(0.06, -0.06, 0.0);
    glVertex3f(0.16, 0.02, 0.0);
    glVertex3f(0.04, 0.02, 0.0);
    glVertex3f(0.0, 0.16, 0.0);
    glVertex3f(-0.04, 0.02, 0.0);
    glVertex3f(-0.16, 0.02, 0.0);
    glVertex3f(-0.06, -0.06, 0.0);
    glVertex3f(-0.1, -0.16, 0.0);
    glEnd();
}
// end of 별 그리기 함수

// 모든 도형 그리기 함수
void drawAll()
{
    glLoadIdentity();
    glTranslatef(-0.5, 0.5, 0);
    drawWhiteCircle(0.5);

    // 작은 원 그리기
    glLoadIdentity();
    glTranslatef(0.5, 0.5, 0);
    drawRedCircle(0.2);

    // 별 그리기
    glLoadIdentity();
    glTranslatef(0, -0.5, 0);
    drawStar();
}
// end of 모든 도형 그리기 함수

// 터키 국기 그리기 함수
void Turkey()
{
    // 터키 국기 배경색
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-0.2, 0, 0);
    drawWhiteCircle(0.5);
    glLoadIdentity();
    glTranslatef(-0.08, 0, 0);
    drawRedCircle(0.4);
    //별 그리기
    glLoadIdentity();
    glTranslatef(0.5, 0, 0);
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(30.0, 0.0, 0.0, 1.0);  // z축 기준으로 30도 회전
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.1, 0.0);
    glVertex3f(0.1, -0.16, 0.0);
    glVertex3f(0.06, -0.06, 0.0);
    glVertex3f(0.16, 0.02, 0.0);
    glVertex3f(0.04, 0.02, 0.0);
    glVertex3f(0.0, 0.16, 0.0);
    glVertex3f(-0.04, 0.02, 0.0);
    glVertex3f(-0.16, 0.02, 0.0);
    glVertex3f(-0.06, -0.06, 0.0);
    glVertex3f(-0.1, -0.16, 0.0);
    glEnd();
    glutSwapBuffers();
}

// 디스플레이 함수
void display()
{
    Turkey();
    if (draw_1_circle) 
    {
        glLoadIdentity();
        glTranslatef(0, 0, 0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
        drawWhiteCircle(0.5);
        glutSwapBuffers();

    }
    // 키보드 2입력 시 작은 원 그리기 (빨간색)
    if (draw_2_circle) 
    {
        glLoadIdentity();
        glTranslatef(0, 0, 0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
        drawRedCircle(0.2);
        glutSwapBuffers();

    }
    // 키보드 3입력 시 별 그리기 (흰색)
    if (draw_3_star) 
    {
        glLoadIdentity();
        glTranslatef(0, 0, 0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
        drawStar();
        glutSwapBuffers();

    }
    // 키보드 엔터 입력 시 모든 도형 그리기
    if (draw_enter_all) 
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
        drawAll();
        glutSwapBuffers();
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