#include "vector3d.h"
#include <iostream>
using namespace std;

Vector3d::Vector3d() {
	x=0.0;
	y=0.0;
	z=0.0;
}

Vector3d::Vector3d(double x_, double y_, double z_) {
	this->x=x_;
	this->y=y_;
	this->z=z_;
}

Vector3d::Vector3d(Vector3d* A) {
	this->x=A->get_x();
	this->y=A->get_y();
	this->z=A->get_z();
}

double Vector3d::get_x() {
	return this->x;
}

double Vector3d::get_y() {
	return this->y;
}

double Vector3d::get_z() {
	return this->z;
}

void Vector3d::print() {
	cout << this->x << " " << this->y << " " << this->z << endl;
}

