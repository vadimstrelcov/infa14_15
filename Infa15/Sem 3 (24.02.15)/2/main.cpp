#include <iostream>
#include "vector3d.h"

using namespace std;

Vector3d operator + (Vector3d A, Vector3d B) {
	return Vector3d(A.get_x()+B.get_x(),A.get_y()+B.get_y(),A.get_z()+B.get_z());
}
	
Vector3d operator - (Vector3d A, Vector3d B) {
	return Vector3d(A.get_x()-B.get_x(),A.get_y()-B.get_y(),A.get_z()-B.get_z());
}

double operator * (Vector3d A, Vector3d B) {
	return A.get_x()*B.get_x()+A.get_y()*B.get_y()+A.get_z()*B.get_z();
}

bool operator == (Vector3d A, Vector3d B) {
	return (A.get_x()==B.get_x() && A.get_y()==B.get_y() && A.get_z()==B.get_z());
}

std::ostream & operator << (std::ostream &os, Vector3d B) {
	os << B.get_x() << " " << B.get_y() << " " << B.get_z() << endl;
	return os;
}

int main() {
	Vector3d a(1.0,5.0,0.0),b(1.0,-2.0,1.0),c;
	c=a;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	Vector3d Sum=a+b,Sub=a-b;
	double scal=a*b;
	cout << (int)(a==c) << " " << (int)(a==b) << " " << scal << endl;
	return 0;
}

