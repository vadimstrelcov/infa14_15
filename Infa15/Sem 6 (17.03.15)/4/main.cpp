#include "lib.h"
#include <iostream>

int main()
{
    Vector<int, 3> X, Y, Z;
    X.set_n(0, 1);
    X.set_n(1, 0);
    X.set_n(2, 0);
	Y.set_n(0, 0);
    Y.set_n(1, 1);
    Y.set_n(2, 0);
	Z=X*Y;
	std::cout << (int)(X==Y) << "\n";
    std::cout << Z.get_n(0) << "\n";
    std::cout << Z.get_n(1) << "\n";
    std::cout << Z.get_n(2) << "\n";
    return 0;
}
