#include <iostream>
#include <cmath>

class Abstract_Math {
public:
    virtual void who()=0;
	virtual double q()=0;
};

class Double: public Abstract_Math {
private:
	double x;
public:
	Double();
	Double(double);
	double get_x();
	void set_x(double);
	void who();
	double q();
	friend Double operator + (Double, Double);
	friend Double operator - (Double, Double);
	friend Double operator * (Double, Double);
	friend Double operator / (Double, Double);
	friend bool operator == (Double, Double);
	friend bool operator != (Double, Double);
	friend bool operator > (Double, Double);
	friend bool operator < (Double, Double);
	friend bool operator >= (Double, Double);
	friend bool operator <= (Double, Double);
};

Double::Double() {
	this->x=0.0;
}

Double::Double(double X) {
	this->x=X;
}

double Double::get_x() {
	return this->x;
}

void Double::set_x(double A) {
	this->x=A;
}

void Double::who() {
	std::cout << "Double\n";
}

double Double::q() {
	return this->get_x();
}



class Complex: public Abstract_Math {
private:
	double re, im;
public:
	Complex();
	Complex(double, double);
	double get_re();
	double get_im();
	void set_re(double);
	void set_im(double);
    void who();
	double q();
	friend Complex operator + (Complex, Complex);
	friend Complex operator - (Complex, Complex);
	friend Complex operator * (Complex, Complex);
	friend Complex operator / (Complex, Complex);
	friend bool operator == (Complex, Complex);
	friend bool operator != (Complex, Complex);
	friend bool operator > (Complex, Complex);
	friend bool operator < (Complex, Complex);
	friend bool operator >= (Complex, Complex);
	friend bool operator <= (Complex, Complex);
};

Complex::Complex() {
	this->re=0.0;
	this->im=0.0;
}

Complex::Complex(double re_, double im_) {
	this->re=re_;
	this->im=im_;
}

double Complex::get_re() {
	return this->re;
}

double Complex::get_im() {
	return this->im;
}

void Complex::set_re(double A) {
	this->re=A;
}

void Complex::set_im(double A) {
	this->im=A;
}

void Complex::who() {
	std::cout << "Complex\n";
}

double Complex::q() {
	return sqrt(this->get_re()*this->get_re()+this->get_im()*this->get_im());
}



class Vector2D: public Abstract_Math {
private:
	double x,y;
public:
	Vector2D();
	Vector2D(double, double);
	double get_x();
	double get_y();
	void set_x(double);
	void set_y(double);
	void who();
	double q();
	friend Vector2D operator + (Vector2D);
	friend Vector2D operator - (Vector2D);
	friend double operator * (Vector2D);
	friend bool operator == (Vector2D, Vector2D);
	friend bool operator != (Vector2D, Vector2D);
	friend bool operator > (Vector2D, Vector2D);
	friend bool operator < (Vector2D, Vector2D);
	friend bool operator >= (Vector2D, Vector2D);
	friend bool operator <= (Vector2D, Vector2D);
};

Vector2D::Vector2D() {
	this->x=0.0;
	this->y=0.0;
}

Vector2D::Vector2D(double X, double Y) {
	this->x=X;
	this->y=Y;
}

double Vector2D::get_x() {
	return this->x;
}

double Vector2D::get_y() {
	return this->y;
}

void Vector2D::set_x(double A) {
	this->x=A;
}

void Vector2D::set_y(double A) {
	this->y=A;
}

void Vector2D::who() {
	std::cout << "Vector2D\n";
}

double Vector2D::q() {
	return sqrt(this->get_x()*this->get_x()+this->get_y()*this->get_y());
}



class Vector3D: public Abstract_Math {
private:
	double x,y,z;
public:
	Vector3D();
	Vector3D(double, double, double);
	double get_x();
	double get_y();
	double get_z();
	void set_x(double);
	void set_y(double);
	void set_z(double);
	void who();
	double q();
	friend Vector3D operator + (Vector3D);
	friend Vector3D operator - (Vector3D);
	friend double operator * (Vector3D);
	friend bool operator == (Vector3D, Vector3D);
	friend bool operator != (Vector3D, Vector3D);
	friend bool operator > (Vector3D, Vector3D);
	friend bool operator < (Vector3D, Vector3D);
	friend bool operator >= (Vector3D, Vector3D);
	friend bool operator <= (Vector3D, Vector3D);
};

Vector3D::Vector3D() {
	this->x=0.0;
	this->y=0.0;
	this->z=0.0;
}

Vector3D::Vector3D(double X, double Y, double Z) {
	this->x=X;
	this->y=Y;
	this->z=Z;
}

double Vector3D::get_x() {
	return this->x;
}

double Vector3D::get_y() {
	return this->y;
}

double Vector3D::get_z() {
	return this->z;
}

void Vector3D::set_x(double A) {
	this->x=A;
}

void Vector3D::set_y(double A) {
	this->y=A;
}

void Vector3D::set_z(double A) {
	this->z=A;
}

void Vector3D::who() {
	std::cout << "Vector3D\n";
}

double Vector3D::q() {
	return sqrt(this->get_x()*this->get_x()+this->get_y()*this->get_y()+this->get_z()*this->get_z());
}



void show_who(Abstract_Math *r) {
    r->who();
}

void show_q(Abstract_Math *r) {
	std::cout << r->q() << std::endl;
}



Double operator+ (Double A, Double B) {
	return Double(A.get_x()+B.get_x());
}

Double operator- (Double A, Double B) {
	return Double(A.get_x()+B.get_x());
}

Double operator* (Double A, Double B) {
	return Double(A.get_x()*B.get_x());
}

Double operator/ (Double A, Double B) {
	if (B.get_x()!=0.0) {
		return Double(A.get_x()+B.get_x());
	} else {
		return A;
	}
}

bool operator== (Double A, Double B) {
	return (A.get_x()==B.get_x());
}

bool operator!= (Double A, Double B) {
	return (A.get_x()!=B.get_x());
}

bool operator> (Double A, Double B) {
	return (A.get_x()>B.get_x());
}

bool operator< (Double A, Double B) {
	return (A.get_x()<B.get_x());
}

bool operator>= (Double A, Double B) {
	return (A.get_x()>=B.get_x());
}

bool operator<= (Double A, Double B) {
	return (A.get_x()<=B.get_x());
}

Complex operator+ (Complex A, Complex B) {
	return Complex(A.get_re()+B.get_re(),A.get_im()+B.get_im());
}

Complex operator- (Complex A, Complex B) {
	return Complex(A.get_re()-B.get_re(),A.get_im()-B.get_im());
}

Complex operator* (Complex A, Complex B) {
   	return Complex(A.get_re()*B.get_re()-A.get_im()*B.get_im(),A.get_re()*B.get_im()+A.get_im()*B.get_re());
}

Complex operator/ (Complex A, Complex B) {
	if (B.q()!=0.0) {
		return Complex( (A.get_re()*B.get_re()+A.get_im()*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*A.get_im()-B.get_im()*A.get_re())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
	} else {
		return A;
	}
}

bool operator== (Complex A, Complex B) {
	return (A.get_re()==B.get_re() && A.get_im()==B.get_im());
}

bool operator!= (Complex A, Complex B) {
	return (A.get_re()!=B.get_re() || A.get_im()!=B.get_im());
}

bool operator> (Complex A, Complex B) {
	return (A.q()>B.q());
}

bool operator< (Complex A, Complex B) {
	return (A.q()<B.q());
}

bool operator>= (Complex A, Complex B) {
	return (A.q()>=B.q());
}

bool operator<= (Complex A, Complex B) {
	return (A.q()<=B.q());
}



Vector2D operator+ (Vector2D A, Vector2D B) {
	return Vector2D(A.get_x()+B.get_x(),A.get_y()+B.get_y());
}

Vector2D operator- (Vector2D A, Vector2D B) {
	return Vector2D(A.get_x()-B.get_x(),A.get_y()-B.get_y());
}

double operator* (Vector2D A, Vector2D B) {
   	return A.get_x()*B.get_x()+A.get_y()*B.get_y();
}

bool operator== (Vector2D A, Vector2D B) {
	return (A.get_x()==B.get_x() && A.get_y()==B.get_y());
}

bool operator!= (Vector2D A, Vector2D B) {
	return (A.get_x()!=B.get_x() || A.get_y()!=B.get_y());
}

bool operator> (Vector2D A, Vector2D B) {
	return (A.q()>B.q());
}

bool operator< (Vector2D A, Vector2D B) {
	return (A.q()<B.q());
}

bool operator>= (Vector2D A, Vector2D B) {
	return (A.q()>=B.q());
}

bool operator<= (Vector2D A, Vector2D B) {
	return (A.q()<=B.q());
}



Vector3D operator+ (Vector3D A, Vector3D B) {
	return Vector3D(A.get_x()+B.get_x(),A.get_y()+B.get_y(),A.get_z()+B.get_z());
}

Vector3D operator- (Vector3D A, Vector3D B) {
	return Vector3D(A.get_x()-B.get_x(),A.get_y()-B.get_y(),A.get_z()-B.get_z());
}

double operator* (Vector3D A, Vector3D B) {
   	return A.get_x()*B.get_x()+A.get_y()*B.get_y()+A.get_z()*B.get_z();
}

bool operator== (Vector3D A, Vector3D B) {
	return (A.get_x()==B.get_x() && A.get_y()==B.get_y() && A.get_z()==B.get_z());
}

bool operator!= (Vector3D A, Vector3D B) {
	return (A.get_x()!=B.get_x() || A.get_y()!=B.get_y() || A.get_z()!=B.get_z());
}

bool operator> (Vector3D A, Vector3D B) {
	return (A.q()>B.q());
}

bool operator< (Vector3D A, Vector3D B) {
	return (A.q()<B.q());
}

bool operator>= (Vector3D A, Vector3D B) {
	return (A.q()>=B.q());
}

bool operator<= (Vector3D A, Vector3D B) {
	return (A.q()<=B.q());
}



int main() {
    Double double_obj(1.0);
    Complex complex_obj(3.0,-4.0);
    Vector2D vector2d_obj(-1.0,2.0);
    Vector3D vector3d_obj(1.0,2.0,3.0);

    show_who(&double_obj);
	show_q(&double_obj);

    show_who(&complex_obj);
	show_q(&complex_obj);

	show_who(&vector2d_obj);
	show_q(&vector2d_obj);


	show_who(&vector3d_obj);
	show_q(&vector3d_obj);

	return 0;
}
