#include <iostream>
#include <cstdio>
#include <cstdlib>
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
	void print(bool);
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

void Double::print(bool flag=1) {
	printf("%lf", this->x);
	if (flag) {
		printf("\n");
	}
}

void Double::who() {
	std::cout << "Double\n";
}

double Double::q() {
	return this->get_x();
}



template <class T>
class Complex: public Abstract_Math {
private:
	T re, im;
public:
	Complex();
	Complex(T, T);
	Complex(Complex<T>*);
	T get_re();
	T get_im();
	void set_re(T);
	void set_im(T);
	void print(bool);
    void who();
	double q();
	template <typename U> friend Complex<U> operator+ (Complex<U>, Complex<U>);
	template <typename U> friend Complex<U> operator- (Complex<U>, Complex<U>);
	template <typename U> friend Complex<U> operator* (Complex<U>, Complex<U>);
	template <typename U> friend Complex<U> operator/ (Complex<U>, Complex<U>);
	template <typename U> friend bool operator== (Complex<U>, Complex<T>);
	template <typename U> friend bool operator!= (Complex<U>, Complex<U>);
	template <typename U> friend bool operator> (Complex<U>, Complex<U>);
	template <typename U> friend bool operator< (Complex<U>, Complex<U>);
	template <typename U> friend bool operator>= (Complex<U>, Complex<U>);
	template <typename U> friend bool operator<= (Complex<U>, Complex<U>);
};

template <typename T>
Complex<T>::Complex() {
	this->re=0;
	this->im=0;
}

template <typename T>
Complex<T>::Complex(T re_, T im_) {
	this->re=re_;
	this->im=im_;
}

template <typename T>
Complex<T>::Complex(Complex<T>* A) {
	this->re=A->get_re();
	this->im=A->get_im();
}

template <typename T>
T Complex<T>::get_re() {
	return this->re;
}

template <typename T>
T Complex<T>::get_im() {
	return this->im;
}

template <typename T>
void Complex<T>::set_re(T A) {
	this->re=A;
}

template <typename T>
void Complex<T>::set_im(T A) {
	this->im=A;
}

template <typename T>
void Complex<T>::print(bool flag=1) {
	printf("(%lf;%lf)",this->re,this->im);
	if (flag) {
		printf("\n");
	}
}

template <typename T>
void Complex<T>::who() {
	std::cout << "Complex\n";
}

template <typename T>
double Complex<T>::q() {
	return sqrt(this->get_re()*this->get_re()+this->get_im()*this->get_im());
}



template <typename T, int length>
class Vector: public Abstract_Math {
private:
	T mas[length];
public:
	Vector();
	Vector(Vector<T, length>*);
	T get_ind(int);
	void set_ind(int, T);
	void print(bool);
	void who();
	double q();
	template <typename U, int llength> friend Vector<U, llength> operator+ (Vector<U, llength>);
	template <typename U, int llength> friend Vector<U, llength> operator- (Vector<U, llength>);
	template <typename U, int llength> friend double operator* (Vector<U, llength>, Vector<U, llength>);
	template <typename U, int llength> friend bool operator== (Vector<U, llength>, Vector<U, llength>);
	template <typename U, int llength> friend bool operator!= (Vector<U, llength>, Vector<U, llength>);
};

template <typename T, int length>
Vector<T, length>::Vector() {
	for (int i=0;i<length;i++) {
		this->mas[i]=0;
	}
}

template <typename T, int length>
Vector<T, length>::Vector(Vector<T, length>* A) {
	for (int i=0;i<length;i++) {
		this->mas[i]=A->get_ind(i);
	}
}

template <typename T, int length>
T Vector<T, length>::get_ind(int i) {
	if (i<0 || i>=length) {
		std::cerr << "Out of range\n";
		exit(1);
	} else {
		return this->mas[i];
	}
}

template <typename T, int length>
void Vector<T, length>::set_ind(int i, T A) {
	if (i<0 || i>=length) {
		std::cerr << "Out of range\n";
		exit(1);
	} else {
		this->mas[i]=A;
	}
}

template <typename T, int length>
void Vector<T, length>::who() {
	std::cout << "Vector\n";
}

template <typename T, int length>
double Vector<T, length>::q() {
	double sum=0.0;
	for (int i=0;i<length;i++) {
		sum+=this->get_ind(i)*this->get_ind(i);
	}
	return sqrt(sum);
}



template <typename T, int length_y, int length_x>
class Matrix
{
private:
	T mas[length_y][length_x];
public:
	Matrix();
	Matrix(Matrix<T, length_y, length_x>*);
	T get_ind(int, int);
	void set_ind(int, int, T);
	void print();
	void who();
	double q();
	template <typename U> friend Matrix<U, length_y, length_x> operator + (Matrix<U, length_y, length_x>);
	template <typename U> friend Matrix<U, length_y, length_x> operator - (Matrix<U, length_y, length_x>);
	template <typename U> friend double operator* (Matrix<U, length_y, length_x>, Matrix<U, length_y, length_x>);
	template <typename U> friend bool operator== (Matrix<U, length_y, length_x>, Matrix<U, length_y, length_x>);
	template <typename U> friend bool operator!= (Matrix<U, length_y, length_x>, Matrix<U, length_y, length_x>);
};

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x>::Matrix() {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			this->mas[i][j]=0;
		}
	}
}

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x>::Matrix(Matrix<T, length_y, length_x>* A) {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			this->mas[i][j]=A->get_id(i,j);
		}
	}
}

template <typename T, int length_y, int length_x>
T Matrix<T, length_y, length_x>::get_ind(int i, int j) {
	return this->mas[i][j];
}

template <typename T, int length_x, int length_y>
void Matrix<T, length_x, length_y>::set_ind(int i, int j, T A) {
	if (i<0 || i>=length_y || j<0 || j>=length_x) {
		std::cerr << "Out of range\n";
		exit(1);
	} else {
		this->mas[i][j]=A;
	}
}

template <typename T, int length_y, int length_x>
void Matrix<T, length_y, length_x>::print() {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			printf("%lf ",this->mas[i][j]);
		}
		printf("\n");
	}
}

template <typename T, int length_y, int length_x>
void Matrix<T, length_y, length_x>::who() {
	std::cout << "Matrix\n";
}

template <typename T, int length_y, int length_x>
double Matrix<T, length_y, length_x>::q() {
	double res=1.0;
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			res*=fabs(this->mas[i][j]);
		}
	}
	return res;
}





void show_who(Abstract_Math* r) {
    r->who();
}

void show_q(Abstract_Math* r) {
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
		std::cerr << "Divition byb zero\n";
		exit(1);
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

template <class T>
Complex<T> operator+ (Complex<T> A, Complex<T> B) {
	return Complex<T>(A.get_re()+B.get_re(),A.get_im()+B.get_im());
}

template <typename T>
Complex<T> operator- (Complex<T> A, Complex<T> B) {
	return Complex<T>(A.get_re()-B.get_re(),A.get_im()-B.get_im());
}

template <typename T>
Complex<T> operator* (Complex<T> A, Complex<T> B) {
   	return Complex<T>(A.get_re()*B.get_re()-A.get_im()*B.get_im(),A.get_re()*B.get_im()+A.get_im()*B.get_re());
}

template <typename T>
Complex<T> operator/ (Complex<T> A, Complex<T> B) {
	if (B.q()!=0.0) {
		return Complex<T>( (A.get_re()*B.get_re()+A.get_im()*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*A.get_im()-B.get_im()*A.get_re())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
	} else {
		std::cerr << "Divition by zero\n";
		exit(1);
	}
}

template <typename T>
bool operator== (Complex<T> A, Complex<T> B) {
	return (A.get_re()==B.get_re() && A.get_im()==B.get_im());
}

template <typename T>
bool operator!= (Complex<T> A, Complex<T> B) {
	return (A.get_re()!=B.get_re() || A.get_im()!=B.get_im());
}

template <typename T>
bool operator> (Complex<T> A, Complex<T> B) {
	return (A.q()>B.q());
}

template <typename T>
bool operator< (Complex<T> A, Complex<T> B) {
	return (A.q()<B.q());
}

template <typename T>
bool operator>= (Complex<T> A, Complex<T> B) {
	return (A.q()>=B.q());
}

template <typename T>
bool operator<= (Complex<T> A, Complex<T> B) {
	return (A.q()<=B.q());
}

template <typename T, int length>
Vector<T, length> operator+ (Vector<T, length> A, Vector<T, length> B) {
	Vector<T, length> tmp;
	for (int i=0;i<length;i++) {
		tmp.set_id(i,A.get_ind(i)+B.get_ind(i));
	}
	return tmp;
}

template <typename T, int length>
Vector<T, length> operator- (Vector<T, length> A, Vector<T, length> B) {
	Vector<T, length> tmp;
	for (int i=0;i<length;i++) {
		tmp.set_id(i,A.get_ind(i)-B.get_ind(i));
	}
	return tmp;
}

template <typename T, int length>
double operator* (Vector<T, length> A, Vector<T, length> B) {
	double res=0.0;
	for (int i=0;i<length;i++) {
		res+=A.get_ind(i)*B.get_ind(i);
	}
	return res;
}

template <typename T, int length>
bool operator== (Vector<T, length> A, Vector<T, length> B) {
	for (int i=0;i<length;i++) {
		if (A.get_ind(i)!=B.get_ind(i)) {
			return 0;
		}
	}
	return 1;
}

template <typename T, int length>
bool operator!= (Vector<T, length> A, Vector<T, length> B) {
	for (int i=0;i<length;i++) {
		if (A.get_ind(i)!=B.get_ind(i)) {
			return 1;
		}
	}
	return 0;
}

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x> operator+ (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	Matrix<T, length_y, length_x> tmp;
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			tmp.set_ind(i,j,A.get_ind(i,j)+B.get_ind(i,j));
		}
	}
}

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x> operator- (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	Matrix<T, length_y, length_x> tmp;
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			tmp.set_ind(i,j,A.get_ind(i,j)-B.get_ind(i,j));
		}
	}
}

template <typename T, int length_y, int length_x>
bool operator== (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			if (A.get_ind(i,j)!=B.get_ind(i,j)) {
				return 0;
			}
		}
	}
	return 1;
}

template <typename T, int length_y, int length_x>
bool operator!= (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			if (A.get_ind(i,j)!=B.get_ind(i,j)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
    Double double_obj(1.0);
    Complex<double> complex_obj(3.0,-4.0);
    std::cout << complex_obj.q() << std::endl;
	Vector<double, 3> A, B;
	A.set_ind(0, 1.0);
	A.set_ind(1, 0.0);
	A.set_ind(2, 10.0);
	B.set_ind(0, -1.0);
	B.set_ind(1, -5.0);
	B.set_ind(2, 1.0);
	double ans=A*B;
	std::cout << ans << std::endl;
	return 0;
}
