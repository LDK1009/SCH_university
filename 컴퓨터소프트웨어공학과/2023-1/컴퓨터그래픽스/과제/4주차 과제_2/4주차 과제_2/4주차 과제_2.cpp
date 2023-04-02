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
int MouseX1, MouseY1, MouseX2, MouseY2;
int numStar = 0 ;
float starPositions[100][2];
GLfloat rotationAngle = 0.0f;
bool reverseRotation = false;
GLint index = 0;
GLfloat Delta = 0.0f;
GLfloat angle = 0;

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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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

void idleProcess()
{
    angle += 0.0001;
    if (angle > 360.0)
        angle = 0.0f;
    glutPostRedisplay();

}

void timerProcess(int value)
{
    if (Delta < 2.0f)
    {
        Delta = Delta + 0.01f;

        if (++index >= 8)
        {
            index = 0;
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
    else
    {
        Delta = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(2000, timerProcess, 1);
}

// 별 그리기 함수
void drawFirstStar(int x, int y, int z, float size)
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

void drawStar(float cx, float cy, float size, int numPoints) {
    // Calculate outer and inner radius based on size
    float outerRadius = size;
    float innerRadius = size / 2.5f;

    // Draw star
    glBegin(GL_POLYGON);
    for (int i = 0; i < numPoints * 2; i++) {
        float angle = i * 360.0f / (numPoints * 2) * 3.14159f / 180;
        float radius = i % 2 == 0 ? outerRadius : innerRadius;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}



// 선 그리기 함수
void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
// end of 선 그리기 함수

// 디스플레이 함수
void display()
{
    drawFirstStar(0, 0, 0, 0.1);
    glutSwapBuffers();
    // Draw all stars
    for (int i = 0; i < numStar; i++) {
        drawStar(starPositions[i][0], starPositions[i][1], 0.2f, 6);
    }

    // Draw lines between stars
    for (int i = 0; i < numStar - 1; i++) {
        for (int j = i + 1; j < numStar; j++) {
            glColor3f(1.0f, 1.0f, 1.0f);
            drawLine((starPositions[i][0] + starPositions[j][0]) / 2.0f,
                (starPositions[i][1] + starPositions[j][1]) / 2.0f,
                (starPositions[i][0] + starPositions[j][0]) / 2.0f,
                (starPositions[i][1] + starPositions[j][1]) / 2.0f);
        }
    }

    // Draw lines between stars
    for (int i = 0; i < numStar - 1; i++) {
        for (int j = i + 1; j < numStar; j++) {
            glColor3f(1.0f, 1.0f, 1.0f);
            drawLine(starPositions[i][0], starPositions[i][1],
                starPositions[j][0], starPositions[j][1]);
        }
    }

    glutSwapBuffers();
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
        // Add new star at clicked position
        float cx = ((float)x / glutGet(GLUT_WINDOW_WIDTH) - 0.5f) * 2.0f;
        float cy = ((float)(glutGet(GLUT_WINDOW_HEIGHT) - y) / glutGet(GLUT_WINDOW_HEIGHT) - 0.5f) * 2.0f;
        starPositions[numStar][0] = cx;
        starPositions[numStar][1] = cy;
        numStar++;

        glutPostRedisplay();
    }
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        MouseMiddle = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

        glutPostRedisplay();
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