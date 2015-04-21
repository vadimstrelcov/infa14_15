#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <omp.h>

const int n=100;
const int m=100;

class Matrix
{
private:
	double mas[n][m];
public:
	Matrix();
	Matrix(Matrix*);
	double get_ind(int, int);
	void set_ind(int, int, double);
	void print();
	friend Matrix operator+ (Matrix);
	friend Matrix operator* (Matrix, Matrix);
};

Matrix::Matrix() {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			this->mas[i][j]=0.0;
		}
	}
}

Matrix::Matrix(Matrix* A) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			this->mas[i][j]=A->get_ind(i,j);
		}
	}
}

double Matrix::get_ind(int i, int j) {
	return this->mas[i][j];
}

void Matrix::set_ind(int i, int j, double A) {
	this->mas[i][j]=A;
}

void Matrix::print() {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			printf("%lg ",this->mas[i][j]);
		}
		printf("\n");
	}
}

Matrix operator+ (Matrix A, Matrix B) {
	Matrix tmp;
	#pragma omp parallel for
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			tmp.set_ind(i,j,A.get_ind(i,j)+B.get_ind(i,j));
		}
	}
	return tmp;
}

Matrix operator* (Matrix A, Matrix B) {
	Matrix tmp;
	if (n==m) {
		#pragma omp paraller for
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				double q=0.0;
				for (int k=0;k<n;k++) {
					q+=A.get_ind(i,k)*B.get_ind(k,j);
				}
				tmp.set_ind(i,j,q);
			}
		}
	}
	return tmp;
}

int main(int argc, char **argv) {
	Matrix A, B;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			A.set_ind(i,j, i*j+4);
			B.set_ind(i,j, i*j-2);
		}
	}
	double start_time=omp_get_wtime();
	Matrix C=A+B;
	printf("Calculation C: %lf sec\n", omp_get_wtime()-start_time);
	start_time=omp_get_wtime();
	Matrix D=A*B;
	printf("Calculation D: %lf sec\n", omp_get_wtime()-start_time);
	return 0;
}
