#include "point2d.h"
#include <iostream>
using namespace std;

Point2d::Point2d() {
	x=0.0;
	y=0.0;
}

Point2d::Point2d(double x_, double y_) {
	x=x_;
	y=y_;
}

Point2d::Point2d(Vector2d* A) {
	x=A->get_x();
	y=A->get_y();
}

Point2d::Point2d(Point2d A, Vector2d B) {
	x=A.get_x()+B.get_x();
	y=A.get_y()+B.get_y();
}

double Point2d::get_x() {
	return x;
}

double Point2d::get_y() {
	return y;
}

void Point2d::print() {
	cout << x << " " << y <<endl;
}
