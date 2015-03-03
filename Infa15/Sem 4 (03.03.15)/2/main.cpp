#include <iostream>
#include "human.h"
#include "student.h"
#include "advstudent.h"
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    advstudent *advstud = new advstudent [N];
    for (int i=2,j=0;j<N;i++) {
	advstud[j++] = advstudent(argv[i],argv[i+1],argv[i+2],atoi(argv[i+3]),atoi(argv[i+4]));
	i+=4;
    }
    for (int i=0;i<N;i++) {
	std::cout<< advstud[i].get_full_name() << " " << advstud[i].get_score() << " " << advstud[i].get_flag()<<std::endl;
    }

    delete [] advstud;

    return 0;
}
