#include <iostream>
#include "vector2d.h"
using namespace std;

int main() {	
	Vector2d A(5.0,11),B(4.0,12.0),C;
	C=A.sum(B);
	C.print();
	C=A+B;	
	C.print();
	C=A-B;
	C.print();
	C=A*3.5;
	C.print();
	cout << (int)(A==B) << endl;
	A=Vector2d(&B);
	A.print();
	cout << (int)(A==B) << endl;
	return 0;
}

