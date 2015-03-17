#include <iostream>

class Class1
{
public:
	int a,b;
	Class1();
	Class1(int, int);
	int sum();
};

Class1::Class1() {
	this->a=0;
	this->b=0;
}

Class1::Class1(int A, int B) {
	this->a=A;
	this->b=B;
}

int Class1::sum() {
	return this->a+this->b;
}

class Class2
{
public:
	double a,b;
	Class2();
	Class2(double, double);
	double sum();
};

Class2::Class2() {
	this->a=0.0;
	this->b=0.0;
}

Class2::Class2(double A, double B) {
	this->a=A;
	this->b=B;
}

double Class2::sum() {
	return this->a+this->b;
}

int main() {
	Class1 class1_obj(10,1);
	Class2 class2_obj(1.0,4.0);
	std::cout << class1_obj.sum() << " " << class2_obj.sum() << std::endl;
	return 0;
}
