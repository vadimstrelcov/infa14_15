#include <iostream>
#include "point2d.h"

using namespace std;

int main() {
	Vector2d a(1.0,5.0),b(&a);
	Point2d A(&a),C(5.0,2.0),D(C,b);
	a.print();
	b.print();
	A.print();
	C.print();
	D.print();
	return 0;
}
