#include "CCircle.h"

CCircle::CCircle() {
	setCenter(vec3(0.0f));
	setRadius(1.0f);
}
CCircle::CCircle(float radius, vec3 center) {
	setCenter(center);
	setRadius(radius);
}

CCircle::~CCircle() {

}

void CCircle::setCenter(vec3 center) {
	this->center = center;
}
void CCircle::setRadius(float radius) {
	this->radius = radius;
}
vec3 CCircle::getCenter() {
	return this->center;
}
float CCircle::getRadius() {
	return this->radius;
}