#include <cstdio>
#include <iostream>
#include <cmath>

#include "Polygon.h"

int main(int argc, char** argv) {

	printf("%d\n",(int)sizeof(Polygon));
	double h_t=0.001;
	int steps=100;
	/*
		input1: 60 60
		input2: 65 55
		input3: 75 75
		input4: 100 70
		input5: 100 100
		input6: 100 100
	*/
    Polygon polygon("tests/input5.txt", 1, 20, 20, h_t);
   	printf("%d\n",(int)sizeof(polygon));
    polygon.get_partition();


    for (int count=0;count<1000;count++) {
		polygon.solve(count*steps*h_t, steps);
		printf("%d\n",count);
	}

	return 0;
}
