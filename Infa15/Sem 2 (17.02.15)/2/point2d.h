#include "vector2d.h"
class Point2d {
private:
	double x,y;
public:	
	Point2d();
	Point2d(double x_, double y_);
	Point2d(Vector2d* A);
	Point2d(Point2d A, Vector2d B);
	double get_x();
	double get_y();
	void print();
};
