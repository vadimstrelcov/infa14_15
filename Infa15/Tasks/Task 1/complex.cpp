#include <iostream>
#include "complex.h"
#include <cmath>
#include <cstdlib>
using namespace std;

complex::complex() {
}

complex::complex(double re_, double im_) {
	re=re_;
	im=im_;
}

void complex::set_re(double re_) {
	re=re_;
}

void complex::set_im(double im_) {
	im=im_;
}

double complex::get_re() {
	return re;
}

double complex::get_im() {
	return im;
}

void complex::print() {
	cout<<"("<<re<<";"<<im<<")"<<endl;
}

void complex::input() {
	cin>>re>>im;
}

complex complex::sum(complex B) {
	return complex(re+B.get_re(),im+B.get_im());
}

complex complex::sub(complex B) {
	return complex(re-B.get_re(),im-B.get_im());
}

complex complex::mult(complex B) {
	return complex(re*B.get_re()-im*B.get_im(),re*B.get_im()+im*B.get_re());
}
complex complex::div(complex B) {
	if (fabs(B.get_re())<1e-10 && fabs(B.get_im())<1e-10) {
		cerr<<"division by 0";
		exit(1);
	} else {
		return complex( (re*B.get_re()+im*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*im-B.get_im()*re)/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
	}
		
}

complex complex::conj() {
	return complex(re,-im);
}

double complex::modul() {
	return sqrt(re*re+im*im);
}
