#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

namespace Math {
	class complex {
	private:
		double re, im;
	public: 
		complex() {
		}
		complex(double re_, double im_) {
			re=re_;
			im=im_;
		}
		void set_re(double re_) {
			re=re_;
		}
		void set_im(double im_) {
			im=im_;
		}
		double get_re() {
			return re;
		}
		double get_im() {
			return im;
		}
		void print() {
			cout<<"("<<re<<";"<<im<<")"<<endl;
		}
		void input() {
			cin>>re>>im;
		}
	
		complex sum(complex B) {
			return complex(re+B.get_re(),im+B.get_im());
		}
		complex sub(complex B) {
			return complex(re-B.get_re(),im-B.get_im());
		}
		complex mult(complex B) {
			return complex(re*B.get_re()-im*B.get_im(),re*B.get_im()+im*B.get_re());
		}
		complex div(complex B) {
			if (fabs(B.get_re())<1e-10 && fabs(B.get_im())<1e-10) {
				cerr<<"division by 0";
				exit(1);
			} else {
				return complex( (re*B.get_re()+im*B.get_im())/(B.get_re()*B.get_re()+B.get_im()*B.get_im()), (B.get_re()*im-B.get_im()*re)/(B.get_re()*B.get_re()+B.get_im()*B.get_im()) );
			}
		}
		
		complex conj() {
			return complex(re,-im);
		}
		double modul() {
			return sqrt(re*re+im*im);
		}
	};

	complex A,B;
}

int main() {
	Math::A.input();
	Math::A.print();
	Math::B.input();
	Math::B.print();
	Math::A=Math::A.sum(Math::B);
	Math::A.print();
	Math::A=Math::A.sub(Math::B);
	Math::A.print();
	Math::A=Math::A.mult(Math::B);
	Math::A.print();
	Math::A=Math::A.div(Math::B);
	Math::A.print();
	Math::A=Math::A.conj();
	Math::A.print();
	cout<< Math::A.modul() << endl;
	return 0;
}




