#include <iostream>
#include "complex.h"
#include <cmath>
#include <cstdlib>
using namespace std;

complex::complex() {
}

complex::complex(double re_, double im_) {
	this->re=re_;
	this->im=im_;
}

complex::complex(complex* B) {
	this->re=B->get_re();
	this->im=B->get_im();
}

void complex::set_re(double re_) {
	this->re=re_;
}

void complex::set_im(double im_) {
	this->im=im_;
}

double complex::get_re() {
	return this->re;
}

double complex::get_im() {
	return this->im;
}

void complex::print() {
	cout<<"("<<this->re<<";"<<this->im<<")"<<endl;
}

void complex::input() {
	cin>>this->re>>this->im;
}

complex complex::sum(complex B) {
	return complex(this->re+B.get_re(),this->im+B.get_im());
}

complex complex::sub(complex B) {
	return complex(this->re-B.get_re(),this->im-B.get_im());
}

complex complex::mult(complex B) {
	return complex(this->re*B.get_re()-this->im*B.get_im(),this->re*B.get_im()+this->im*B.get_re());
}
complex complex::div(complex B) {
	if (fabs(B.get_re())<1e-10 && fabs(B.get_im())<1e-10) {
		cerr<<"division by 0";
		exit(1);
	} else {
		return complex( (this->re*B.get_re()+this->im*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*this->im-B.get_im()*this->re)/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
	}	
}

complex complex::conj() {
	return complex(this->re,-this->im);
}

double complex::modul() {
	return sqrt(this->re*this->re+this->im*this->im);
}

double complex::arg() {
	return atan2(this->im,this->re);
}

complex complex::operator + (complex B) {
	return complex(this->re+B.get_re(),this->im+B.get_im());
}
complex complex::operator + (double x) {
	return complex(this->re+x,this->im);
}

complex complex::operator - (complex B) {
	return complex(this->re-B.get_re(),this->im-B.get_im());
}
complex complex::operator - (double x) {
	return complex(this->re-x,this->im);
}

complex complex::operator * (complex B) {
	return complex(this->re*B.get_re()-this->im*B.get_im(),this->re*B.get_im()+this->im*B.get_re());
}
complex complex::operator * (double x) {
	return complex(this->re*x,this->im*x);
}
	
complex complex::operator / (complex B) {
	if (fabs(B.get_re())<1e-10 && fabs(B.get_im())<1e-10) {
		cerr<<"division by 0";
		exit(1);
	} else {
		return complex( (this->re*B.get_re()+this->im*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*this->im-B.get_im()*this->re)/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
	}
}
complex complex::operator / (double x) {
	if (fabs(x)<1e-10) {
		cerr<<"division by 0";
		exit(1);
	} else {
		return complex(this->re/x,this->im/x);
	}
}
	
bool complex::operator < (complex B) {
	return this->modul()<B.modul();
}
bool complex::operator <= (complex B) {
	return this->modul()<=B.modul();
}
bool complex::operator > (complex B) {
	return this->modul()>B.modul();
}
bool complex::operator >= (complex B) {
	return this->modul()>=B.modul();
}
bool complex::operator == (complex B) {
	return (this->re==B.get_re() && this->im==B.get_im());
}

