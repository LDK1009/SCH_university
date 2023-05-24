#include "CParticle.h"
#include <vector>
#include <ctime>
#include "CCircle.h"
#include <math.h>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#define PI 3.14159265458979323846
using namespace std::chrono;
CParticle particle;
float dt = 0.001f;
float mass = 10.0f;
CParticle* p = NULL;
int frameCount;
int particleCount;
double currentTime, previousTime, deltaTime;
//double start, stop, duration;
CCircle* circle = new CCircle(5, vec3(0));

vector<CParticle> particleContainer;
int n = 0, m = 0;
int x = 0, y = 0;

int initial_time = time(NULL), final_time, frame_count = 0;

class CRectangle {
public:
	CRectangle(vec3 center, float width, float height)
	{
		this->center = center;
		this->width = width;
		this->height= height;

	}
	vec3 getCenter()
	{
		return this->center;
	}
	float getWidth()
	{
		return this->width;
	}
	float getTop() {
		return (center.y + (height / 2));
	}	
	float getBottom() {
		return (center.y - (height / 2));
	}	
	float getLeft() {
		return (center.x - (height / 2));
	}	
	float getRight() {
		return (center.x + (height / 2));
	}

private:
	vec3 center;
	float width;
	float height;
};
CRectangle* rectangle = new CRectangle(vec3(20, 5, 0), 20, 5);

void drawCircle() {
	float tmp_x = 0;
	float tmp_y = 0;
	float tmp_z = 0;
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPointSize(2);
	glBegin(GL_POINTS);

	for (int i = 0; i < 360; i += 1) {
		tmp_x = circle->getRadius() * cos(i * PI / 180);
		tmp_y = circle->getRadius() * sin(i * PI / 180);
		glVertex2f(tmp_x, tmp_y);

	}

	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-50, 0);
	glVertex2f(50, 0);
	glEnd();
	glPopMatrix();
}

void drawRectangle() {
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);

	glVertex2f(rectangle->getLeft(), rectangle->getTop());
	glVertex2f(rectangle->getRight(), rectangle->getTop());
	glVertex2f(rectangle->getRight(), rectangle->getBottom());
	glVertex2f(rectangle->getLeft(), rectangle->getBottom());

	glEnd();
	glPopMatrix();
}

void Timer(int value)
{
	glutTimerFunc(1, Timer, 0);
	glutPostRedisplay();
}

void DrawPartice(CParticle* p, float r, float g, float b)
{
	glPushMatrix();
	glColor4f(r, g, b, 1.0f);
	glPointSize(3);
	glBegin(GL_POINTS);

	glVertex2f(p->getPos().x, p->getPos().y);
	glEnd();
	glPopMatrix();
}

void MyRender()
{
	for (int i = 0; i < particleCount; i++)
	{
		DrawPartice(&particleContainer[i], 1, 1, 1);
	}
}

void Render()
{
	MyRender();
	glutPostRedisplay();
}

void Collision()
{
	for (int i = 0; i < particleCount; i++)
	{
		p = &particleContainer[i];
		float disX = p->getPos().x - circle->getCenter().x;
		float disY = p->getPos().y - circle->getCenter().y;

		if ((sqrt((disX * disX) + (disY * disY)) < circle->getRadius()) || p->getPos().y < 0.2f)
		{
			p->setVel(-0.75f * p->getVel());
		}
		if ((p->getPos().x > rectangle->getLeft() && p->getPos().x < rectangle->getRight()) && (p->getPos().y > 0.2f + rectangle->getBottom() && p->getPos().y < 0.2f + rectangle->getTop()))
		{
			p->setVel(-0.5f * p->getVel());
		}
	}
}

void setForceZero()
{
	for (int i = 0; i < particleCount; i++)
	{
		p = &particleContainer[i];
		p->setForce(vec3(0.0f));

	}
}

void ComputeForce()
{
	for (int i = 0; i < particleCount; i++)
	{
		p = &particleContainer[i];
		p->setMass(mass);
		p->setForce(vec3(0.0f, -9.81f * p->getMass(), 0.0f));
	}
}

void Update()
{
	setForceZero();
	ComputeForce();
	for (int i = 0; i < particleCount; i++)
	{
		p = &particleContainer[i];
		p->update(dt);
	}
}

void Display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Collision();
	Update();
	
	Render();
	drawCircle();

	drawRectangle();
	glutSwapBuffers();

	frame_count++;
	final_time = time(NULL);
	if (final_time = initial_time > 0)
	{
		system("cls");
		cout << "FPS:" << frame_count / (final_time - initial_time) << endl;
		frame_count = 0;
		initial_time = final_time;
	}
}

void Init()
{
	srand((unsigned int)time(0));
	particleCount = 500;
	cout << "Amount of particle:" << particleCount << endl;

	for (int i = 0; i < particleCount; i++)
	{
		x = rand() % 101 - 50;
		y = rand() % 101 + 10;
		particle.setMass(mass);
		particle.setPos(vec3(x, y, 0.0f));
		particleContainer.push_back(particle);
	}

}

void Reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -25, 25, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(1024, 600);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 640) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 480) / 2);
	glutCreateWindow("Particle System");
	
	Init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);

	glutMainLoop();

	return 0;
}
