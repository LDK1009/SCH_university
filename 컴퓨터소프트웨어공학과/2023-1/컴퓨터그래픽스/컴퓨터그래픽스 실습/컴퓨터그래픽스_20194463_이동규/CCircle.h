#pragma once
#include <gl\glut.h>
#include <iostream>
#include "glm\glm.hpp"
#include "glm\gtx\norm.hpp"
#include <iostream>
using namespace glm;
using namespace std;
class CCircle
{
public: 
	CCircle();
	CCircle(float radius, vec3 center);
	~CCircle();

	void setRadius(float radius);
	void setCenter(vec3 center);

	float getRadius();
	vec3 getCenter();

private: 
	float radius;
	vec3 center;
};

