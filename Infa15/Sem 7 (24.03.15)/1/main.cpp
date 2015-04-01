#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

class Abstract_Math {
public:
    virtual void who()=0;
	virtual double q()=0;
};


template <typename T, int length>
class Vector: public Abstract_Math {
private:
	T mas[length];
public:
	Vector();
	Vector(Vector<T, length>*);
	T get_ind(int);
	void set_ind(int, T);
	void print();
	void who();
	double q();
	template <typename U, int llength> friend Vector<U, llength> operator+ (Vector<U, llength>);
	template <typename U, int llength> friend Vector<U, llength> operator- (Vector<U, llength>);
	template <typename U, int llength1, int llength2> friend Vector<U, 3> operator* (Vector<U, llength1>, Vector<U, llength2>);
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
void Vector<T, length>::print() {
	for (int i=0;i<length;i++) {
		printf("%lf ", this->mas[i]);
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
	template <typename U, int length_x1, int length_y1, int length_x2, int length_y2> friend Matrix<U, length_y1, length_x1> operator + (Matrix<U, length_y1, length_x1>, Matrix<U, length_y2, length_x1>);
	template <typename U, int length_x1, int length_y1, int length_x2, int length_y2> friend Matrix<U, length_y1, length_x1> operator - (Matrix<U, length_y1, length_x1>, Matrix<U, length_y2, length_x1>);
	template <typename U, int length_x1, int length_y1, int length_x2, int length_y2> friend Matrix<U, length_y1, length_x2> operator * (Matrix<U, length_y1, length_x1>, Matrix<U, length_y2, length_x1>);
	template <typename U, int length_x1, int length_y1, int length_x2, int length_y2> friend Matrix<U, length_y1, length_x1> operator == (Matrix<U, length_y1, length_x1>, Matrix<U, length_y2, length_x1>);
	template <typename U, int length_x1, int length_y1, int length_x2, int length_y2> friend Matrix<U, length_y1, length_x1> operator != (Matrix<U, length_y1, length_x1>, Matrix<U, length_y2, length_x1>);
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

template <typename T, int length1, int length2>
Vector<T, 3> operator* (Vector<T, length1> A, Vector<T, length2> B) {
	try {
		if (length1!=3 || length2!=3) {
			throw 1;
		}
		Vector<T, 3> C;
		C.set_ind(0, A.get_ind(1)*B.get_ind(2)-A.get_ind(2)*B.get_ind(1));
		C.set_ind(1, A.get_ind(2)*B.get_ind(0)-A.get_ind(0)*B.get_ind(2));
		C.set_ind(2, A.get_ind(0)*B.get_ind(1)-A.get_ind(1)*B.get_ind(0));
		return C;
	}
	catch (int) {
		std::cout << "Not defined Vector<" << length1 << ">*Vector<" << length2 << ">\n";
	}
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


template <typename T, int length_y1, int length_x1, int length_y2, int length_x2>
Matrix<T, length_y1, length_x1> operator+ (Matrix<T, length_y1, length_x1> A, Matrix<T, length_y1, length_x1> B) {
	try {
		if (length_x1!=length_x2 || length_y1!=length_y2) {
			throw 1;
		}
		Matrix<T, length_y1, length_x1> tmp;
		for (int i=0;i<length_y1;i++) {
			for (int j=0;j<length_x1;j++) {
				tmp.set_ind(i,j,A.get_ind(i,j)+B.get_ind(i,j));
			}
		}
	}
	catch (int) {
		std::cerr << "Matrix sizes are not equal\n";
	}
}

template <typename T, int length_y1, int length_x1, int length_y2, int length_x2>
Matrix<T, length_y1, length_x1> operator- (Matrix<T, length_y1, length_x1> A, Matrix<T, length_y2, length_x2> B) {
	try {
		if (length_x1!=length_x2 || length_y1!=length_y2) {
			throw 1;
		}
		Matrix<T, length_y1, length_x1> tmp;
		for (int i=0;i<length_y1;i++) {
			for (int j=0;j<length_x1;j++) {
				tmp.set_ind(i,j,A.get_ind(i,j)-B.get_ind(i,j));
			}
		}
	}
	catch (int) {
		std::cerr << "Matrix sizes are not equal\n";
	}
}

template <typename T, int length_y1, int length_x1, int length_y2, int length_x2>
Matrix<T, length_y1, length_x1> operator* (Matrix<T, length_y1, length_x1> A, Matrix<T, length_y2, length_x2> B) {
	try {
		if (length_x1!=length_y2) {
			throw 1;
		}
		Matrix<T, length_y1, length_x2> tmp;
		for (int i=0;i<length_y1;i++) {
			for (int j=0;j<length_x2;j++) {
				T sum=0;
				for (int k=0;k<length_y2;k++) {
					sum+=A.get_ind(i,k)*B.get_ind(k,j);
				}
				tmp.set_ind(i,j,sum);
			}
		}
		return tmp;
	}
	catch (int) {
		std::cerr << "Matrix sizes are not equal\n";
	}
}

template <typename T, int length_y1, int length_x1, int length_y2, int length_x2>
bool operator== (Matrix<T, length_y1, length_x1> A, Matrix<T, length_y2, length_x2> B) {
	try {
		if (length_x1!=length_x2 || length_y1!=length_y2) {
			throw 1;
		}
		for (int i=0;i<length_y1;i++) {
			for (int j=0;j<length_x1;j++) {
				if (A.get_ind(i,j)!=B.get_ind(i,j)) {
					return 0;
				}
			}
		}
		return 1;
	}
	catch (int) {
		std::cerr << "Matrix sizes are not equal\n";
	}
}

template <typename T, int length_y1, int length_x1, int length_y2, int length_x2>
bool operator!= (Matrix<T, length_y1, length_x1> A, Matrix<T, length_y2, length_x2> B) {
	try {
		if (length_x1!=length_x2 || length_y1!=length_y2) {
			throw 1;
		}
		for (int i=0;i<length_y1;i++) {
			for (int j=0;j<length_x1;j++) {
				if (A.get_ind(i,j)!=B.get_ind(i,j)) {
					return 1;
				}
			}
		}
	}
	catch (int) {
		std::cerr << "Matrix sizes are not equal\n";
	}
	return 0;
}

int main() {
	/*
	Vector<double, 3> A;
	A.set_ind(0, 1.0);
	A.set_ind(1, 0.0);
	A.set_ind(2, 0.0);
	Vector<double, 4> B;
	B.set_ind(0, 0.0);
	B.set_ind(1, 1.0);
	B.set_ind(2, 0.0);
	Vector<double, 3> C=A*B;
	C.print();
	*/
	Matrix<double, 2, 2> A;
	Matrix<double, 2, 2> B;
	A.set_ind(0, 0, 1.0);
	A.set_ind(0, 1, 0.0);
	A.set_ind(1, 0, 0.0);
	A.set_ind(1, 1, 1.0);

	B.set_ind(0, 0, 3.0);
	B.set_ind(0, 1, 4.0);
	B.set_ind(1, 0, 5.0);
	B.set_ind(1, 1, 6.0);

	Matrix<double, 2, 2> C = A*B;

	std::cout << A.get_ind(0,0) << " " << A.get_ind(0,1) << "\n" << A.get_ind(1,0) << " " << A.get_ind(1,1) << std::endl;
	std::cout << B.get_ind(0,0) << " " << B.get_ind(0,1) << "\n" << B.get_ind(1,0) << " " << B.get_ind(1,1) << std::endl;
	std::cout << C.get_ind(0,0) << " " << C.get_ind(0,1) << "\n" << C.get_ind(1,0) << " " << C.get_ind(1,1) << std::endl;

	return 0;
}
