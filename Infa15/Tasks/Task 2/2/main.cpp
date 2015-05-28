#include <iostream>
#include "complex.h"
#include <cmath>

using namespace std;

int main() {
	complex A1,A2;
	A1.input();
	A2.input();
	
	complex SUM,SUB,MULT,DIV,CONJ;
	double modul1,modul2,arg1,arg2;

	SUM=A1.sum(A2);
	SUB=A1.sub(A2);
	MULT=A1.mult(A2);
	DIV=A1.div(A2);
	CONJ=A1.conj();
	modul1=A1.modul();
	modul2=A2.modul();
	arg1=A1.arg();
	arg2=A2.arg();
	
	SUM.print();
	SUB.print();
	MULT.print();
	DIV.print();
	CONJ.print();
	cout << modul1 << " " << modul2 << " " << arg1 << " " << arg2 << endl;
	cout << (int)(A1==A2) << (int)(A1<A2) << (int)(A1<=A2) << (int)(A1>A2) << (int)(A1>=A2) << endl;
	A1=A1+A2;
	A1.print();
	A1=A1-A2;
	A1.print();
	A1=A1*A2;
	A1.print();
	A1=A1/A2;
	A1.print();
		
	return 0;
}

