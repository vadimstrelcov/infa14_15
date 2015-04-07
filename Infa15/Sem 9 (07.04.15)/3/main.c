#include <stdio.h>
#include <omp.h>
#include <limits.h>
#include <math.h>

const int N=20000;
const int threads=1;

int main() {
	double S=0.0;
	int j;
	const double dh=1.0/N;
	double S_[threads];
	for (j=0;j<threads;j++) {
		S_[j]=0.0;
	}
	omp_set_num_threads(threads);
	for (j=0;j<N;j++) {
		S_[omp_get_thread_num()]+=dh*sqrt(1.0-j*j*dh*dh);
	}
	
	for (j=0;j<threads;j++) {
		S+=S_[j];
	}
	
	printf("%lf\n", 4.0*S);
	
	return 0;
}
