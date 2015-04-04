#include <cstdio>
#include <iostream>
#include <cmath>

#include "Polygon.h"

int main(int argc, char** argv) {

	printf("%d\n",(int)sizeof(Polygon));
	double h_t=0.001;
	int steps=1000, n_count=1000;
	/*
		input1:   60  60
		input2:   65  55
		input3:   75  75
		input4:  100  70
		input5:   10  10
		input6:  100 100
		input7:   10  10
		input8:  120 120
		input8:  100 100
		input9:  100 100
		input10:1000 100
		input11-14:1000 1000
		input15: 500 100
	*/
    Polygon polygon("tests/input15.txt", 1, 100, 100, h_t);
   	printf("%d\n",(int)sizeof(polygon));
    polygon.get_partition();

    for (int count=0;count<n_count;count++) {
		polygon.solve(count*steps*h_t, steps);
		printf("%d\n",count);
	}

	return 0;
}
