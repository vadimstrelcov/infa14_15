#include <cstdio>
#include <iostream>
#include <cmath>

#include "Polygon.h"

int main(int argc, char** argv) {

	printf("%d\n",(int)sizeof(Polygon));
	/*
		input1: 60 60
		input2: 65 55
		input3: 75 75
		input4: 100 70
		input5: 100 100
		input6: 100 100
	*/
    Polygon polygon("tests/input6.txt", 100, 100, 1000);
   	printf("%d\n",(int)sizeof(Polygon));
    polygon.get_partition();
    polygon.solve();


	return 0;
}
