#include <GL/glut.h> // OpenGL 라이브러리 헤더 파일
#include <iostream>
using namespace std;

/*
- 1. 윈도우 상에 삼각형 두개를 사용하여 작은 별 하나 그리기(완료)

- 2. 마우스 이벤트를 이용하여 왼쪽 마우스 클릭시에 클릭된 위치
로 별이 생성되면서 별 사이 직선거리의 선(중점을 연결하는
선)을 그리시오. 모든 별이 계속 추가되어야함.
(
2-1. 마우스 x y 좌표를 매개변수로 받아 해당 좌표에 별을 생성하는 함수 coordinate_drawStar() 정의
2-2. if 왼쪽 마우스 클릭 시 x y를 coordinate_drawStar() 매개변수로 입력하여 함수 호출


- 3. 마우스 이벤트를 이용하여 오른쪽 마우스 클릭시에 모든 별이
회전하고 한번 더 클릭하면 토글되어 모든별이 반대로 회전되
도록 만드시오. 오른쪽 마우스 클릭마다 계속 토글 되도록.
3-1. bool RotationCondition_Stop=True(별 정지 상태)
   bool RotationCondition_clockwise=False (별 시계 방향 회전)
   bool RotationCondition_counterclockwise=False (별 반 시계 방향 회전)
   변수 선언 및 초기화

3-2
3-2-1 모든 별이 정지되어 있는 상태에서 마우스 좌클릭시 
if(RotationCondition_Stop==True)
{
if(마우스 좌클릭 시)
{ RotationCondition_clockwise==True }
}
3-2-2 별이 시계 방향으로 회전하고 있을 때 마우스 좌클릭시 반시계 방향으로 변경
if(RotationCondition_clockwise==True) // 별이 회전 중이다
{
    if(마우스 좌클릭 시)
    {
    RotationCondition_clockwise=False; // 시계방향 회전 정지
    RotationCondition_counterclockwise=True;    // 반시계 방향 회전 시작
    }
   
3-2-3 별이 반시계 방향으로 회전하고 있을 때 마우스 좌클릭 시 시계 방향으로 변경  
if(RotationCondition_counterclockwise==True) 
{
    if(마우스 좌클릭 시)
    {
    RotationCondition_counterclockwise=False; //반시계 방향 회전 정지
    RotationCondition_clockwise=True;   // 시계 방향 회전 시작
    }
}

- 4. 마우스 이벤트를 이용하여 마우스 가운데 버튼 클릭시 모든 별
의 색이 바뀌도록 만드시오
if (가운데 버튼 클릭)
    i=0;
    i++;
    별 색깔 = PALETTE[i][3];

*/

/*
과목명 : 컴퓨터그래픽스
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.31
*/

/*
프로그램 오류
*/


// 키보드 입력 중이 아닐 때 도형을 그리지 않기 위해 변수 생성
bool MouseLeft = false, MouseMiddle = false, MouseRight = false;
int mouseX, mouseY;

unsigned char PALETTE[9][3] =
{
    {255,255,255},
    {0,255,255},
    {255,0,255},
    {192,192,192},
    {128,128,128},
    {128,0,0},
    {0,128,0},
    {0,0,128},
    {0,0,0},
};

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


// 별 그리기 함수
void drawStar(int x, int y, int z, float size)
{
    glLoadIdentity();
    glTranslatef(x, y, z);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex3f(size*0.75, size * 0.375, 0.0);
    glVertex3f(size * (- 0.75), size * 0.375, 0.0);
    glVertex3f(0, size * (- 0.75), 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(size * (- 0.75), size * (- 0.375), 0.0);
    glVertex3f(size * 0.75, size * (- 0.375), 0.0);
    glVertex3f(0, size * 0.75, 0.0);
    glEnd();
}
// end of 별 그리기 함수


// 디스플레이 함수
void display()
{
    drawStar(0, 0, 0, 0.1);
    glutSwapBuffers();
    // 마우스 왼쪽 입력 시
    if (MouseLeft)
    {

    }
    // 마우스 가운데 입력 시
    if (MouseMiddle)
    {
        glLoadIdentity();
        glTranslatef(0, 0, 0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT); // 현재 화면 지우기
        glutSwapBuffers();

    }
    // 마우스 오른쪽 입력 시
    if (MouseRight)
    {

    }
}
// end of 디스플레이 함수


// 마우스 콜백 함수
void mouseProcess(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseX = x - glutGet(GLUT_WINDOW_WIDTH) / 2;
        mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
        glTranslatef(mouseX, mouseY, 0);
        drawStar(x, y, 0, 0.1);
        glutSwapBuffers();
    }
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        MouseMiddle = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        MouseRight = true;
    }

}

// end of 마우스 콜백 함수


// 메인 함수
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // GLUT 초기화
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 디스플레이 모드 설정
    glutInitWindowSize(600, 400); // 윈도우 크기 설정
    glutInitWindowPosition(100, 100);   // 윈도우 위치 설정
    glutCreateWindow("4주차 과제_2"); // 윈도우 생성
    init();


    glutDisplayFunc(display); // 디스플레이 콜백 함수 등록
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseProcess); // 키보드 콜백 함수 등록


    glutMainLoop(); // GLUT 메인 루프 실행

    return 0;
}
// end of 메인 함수