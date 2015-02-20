#include <iostream>
#include "vector2d.h"
using namespace std;

Vector2d::Vector2d() {
	this->x=0.0;
	this->y=0.0;
}

Vector2d::Vector2d(double x_, double y_) {
	this->x=x_;
	this->y=y_;
}

Vector2d::Vector2d(Vector2d* A) {
	this->x=A->get_x();
	this->y=A->get_y();
}

double Vector2d::get_x() {
	return this->x;
}

double Vector2d::get_y() {
	return this->y;
}

void Vector2d::print() {
	cout << this->x << " " << this->y << endl;
}

Vector2d Vector2d::sum(Vector2d B) {
	return Vector2d(this->x+B.get_x(),this->y+B.get_y());
}

Vector2d Vector2d::operator + (Vector2d B) {
	return Vector2d(this->x+B.get_x(),this->y+B.get_y());
}

Vector2d Vector2d::operator - (Vector2d B) {
	return Vector2d(this->x-B.get_x(),this->y-B.get_y());
}

bool Vector2d::operator == (Vector2d B) {
	return (this->x==B.get_x() && this->y==B.get_y());
}

double Vector2d::operator * (Vector2d B) {
	return this->x*B.get_x()+this->y*B.get_y();
}

Vector2d Vector2d::operator * (double C) {
	return Vector2d(this->x*C,this->y*C);
}
