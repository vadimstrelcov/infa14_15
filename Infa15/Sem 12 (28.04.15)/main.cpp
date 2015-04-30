#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
using namespace std;

template <class T>
class Complex {
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
	double q();
	template <typename U> friend Complex<U> operator+ (Complex<U>, Complex<U>);
	template <typename U> friend Complex<U> operator- (Complex<U>, Complex<U>);
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
double Complex<T>::q() {
	return sqrt(this->get_re()*this->get_re()+this->get_im()*this->get_im());
}

template <typename T, int length_y, int length_x>
class Matrix
{
private:
	Complex<T> mas[length_y][length_x];
public:
	Matrix();
	Matrix(Matrix<T, length_y, length_x>*);
	Complex<T> get_ind(int, int);
	void set_ind(int, int, Complex<T>*);
	void print(bool);
	double q();
	template <typename U> friend Matrix<U, length_y, length_x> operator + (Matrix<U, length_y, length_x>);
	template <typename U> friend Matrix<U, length_y, length_x> operator - (Matrix<U, length_y, length_x>);
};

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x>::Matrix() {
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			this->mas[i][j].set_im(0.0);
			this->mas[i][j].set_re(0.0);
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
Complex<T> Matrix<T, length_y, length_x>::get_ind(int i, int j) {
	return this->mas[i][j];
}

template <typename T, int length_x, int length_y>
void Matrix<T, length_x, length_y>::set_ind(int i, int j, Complex<T>* A) {
	if (i<0 || i>=length_y || j<0 || j>=length_x) {
		std::cerr << "Out of range\n";
		exit(1);
	} else {
		this->mas[i][j].set_re(A->get_re());
		this->mas[i][j].set_im(A->get_im());
	}
}

template <typename T, int length_y, int length_x>
void Matrix<T, length_y, length_x>::print(bool flag) {
	if (flag) {
		for (int i=0;i<length_y;i++) {
			for (int j=0;j<length_x;j++) {
				this->mas[i][j].print(0);
				printf(" ");
			}
			printf("\n");
		}
	} else {
		for (int i=0;i<length_y;i++) {
			for (int j=0;j<length_x;j++) {
				printf("%lf ", this->mas[i][j].get_re());
			}
			printf(" ");
			for (int j=0;j<length_x;j++) {
				printf("%lf ", this->mas[i][j].get_im());
			}
			printf("\n");
		}
	}
}

template <typename T, int length_y, int length_x>
double Matrix<T, length_y, length_x>::q() {
	double res[4];
	res[0]=this->mas[0][0].q();
	res[1]=this->mas[0][1].q();
	res[2]=this->mas[1][0].q();
	res[3]=this->mas[1][1].q();
	return max(res[0], max(res[1], max(res[2], res[3])));
}

template <class T>
Complex<T> operator+ (Complex<T> A, Complex<T> B) {
	return Complex<T>(A.get_re()+B.get_re(),A.get_im()+B.get_im());
}

template <typename T>
Complex<T> operator- (Complex<T> A, Complex<T> B) {
	return Complex<T>(A.get_re()-B.get_re(),A.get_im()-B.get_im());
}

/*
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
*/

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x> operator+ (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	Matrix<T, length_y, length_x> tmp;
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			Complex<T> z=A.get_ind(i,j)+B.get_ind(i,j);
			tmp.set_ind(i,j,&z);
		}
	}
	return tmp;
}

template <typename T, int length_y, int length_x>
Matrix<T, length_y, length_x> operator- (Matrix<T, length_y, length_x> A, Matrix<T, length_y, length_x> B) {
	Matrix<T, length_y, length_x> tmp;
	for (int i=0;i<length_y;i++) {
		for (int j=0;j<length_x;j++) {
			Complex<T> z=A.get_ind(i,j)-B.get_ind(i,j);
			tmp.set_ind(i,j,&z);
		}
	}
	return tmp;
}

int main() {
	srand(time(NULL));
	const int N=10000;
    Matrix<double,2,2> A[N];
    Matrix<double,2,2> C, D;

    for (int w=0;w<N;w++) {
		for (int i=0;i<2;i++) {
			for (int j=0;j<2;j++) {
				Complex<double> tmp(rand()/(double)RAND_MAX, rand()/(double)RAND_MAX);
				A[w].set_ind(i,j,&tmp);
			}
		}
	}
	C=A[0]+A[1];
    D=A[0]-A[1];
    A[0].print(0);
    A[1].print(0);
    C.print(0);
    C.print(1);
    D.print(0);
    D.print(1);

	double massive[N];
	#pragma omp parallel for
	for (int count=0;count<N;count++) {
		massive[count]=A[count].q();
	}
	for (int i=0;i<N-1;i++) {
		#pragma omp parallel for
		for (int j=i+1;j<N;j++) {
			if (massive[i]>massive[j]) {
				swap(massive[i], massive[j]);
				swap(A[i],A[j]);
			}
		}
	}
	printf("Result of sorting\n");
	for (int count=0;count<N;count++) {
		printf("%lf\n", massive[count]);
		A[count].print(1);
	}

    return 0;
}
