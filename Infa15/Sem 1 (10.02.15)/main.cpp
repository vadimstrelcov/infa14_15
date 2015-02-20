#include <iostream>
#include "sum.h"
using namespace std;

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
