#include <iostream>
#include "vector3d.h"

using namespace std;

int main() {
	Vector3d a(1.0,5.0,0.0),b(1.0,-2.0,1.0),c;
	c=a;
	a.print();
	b.print();
	c.print();
	Vector3d Sum=a+b,Sub=a-b;
	double scal=a*b;
	cout << (int)(a==c) << " " << (int)(a==b) << " " << scal << endl;
	return 0;
}
