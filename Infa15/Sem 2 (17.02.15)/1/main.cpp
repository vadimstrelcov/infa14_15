#include <iostream>
using namespace std;

namespace complex1
{
	int a,b;
}

namespace complex2
{
	int a, b;
}

int main() {

	complex1::a=4;
	complex1::b=5;

	complex2::a=complex1::a;
	complex2::b=complex1::b;

	cout << complex2::a << " " << complex2::b << endl;

	return 0;
}

