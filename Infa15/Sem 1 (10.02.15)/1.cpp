#include <iostream>
using namespace std;

class Sum
{
private:
	int a,b;
public:
	Sum(int a_, int b_);
	int sum_ab();
	void set_a(int a_);
	void set_b(int b_);
	int get_a();
	int get_b();
	void plus(Sum B);
};

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

int main() {
	int x,y;
	cin>>x>>y;
	Sum *XY = new Sum (x,y);
	cout<<XY->sum_ab()<<endl;
	XY->plus(Sum(1,1));
	cout<<XY->get_a()<<" "<<XY->get_b()<<endl;
	delete XY;
	return 0;
}
