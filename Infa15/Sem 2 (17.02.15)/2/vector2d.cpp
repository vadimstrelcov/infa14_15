#include "vector2d.h"
#include <iostream>
using namespace std;

Vector2d::Vector2d() {
	x=0.0;
	y=0.0;
}

Vector2d::Vector2d(double x_, double y_) {
	x=x_;
	y=y_;
}

Vector2d::Vector2d(Vector2d* A) {
	x=A->get_x();
	y=A->get_y();
}

double Vector2d::get_x() {
	return x;
}

double Vector2d::get_y() {
	return y;
}

void Vector2d::print() {
	cout << x << " " << y <<endl;
}
