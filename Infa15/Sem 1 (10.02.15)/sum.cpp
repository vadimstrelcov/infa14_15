#include "sum.h"

Sum::Sum(int a_, int b_) {
	a=a_;
	b=b_;
}

int Sum::sum_ab() {
	return a+b;
}

void Sum::set_a(int a_) {
	a=a_;
}

void Sum::set_b(int b_) {
	b=b_;
}

int Sum::get_a() {
	return a;
}

int Sum::get_b() {
	return b;
}

void Sum::plus(Sum B) {
	a+=B.get_a();
	b+=B.get_b();
}
