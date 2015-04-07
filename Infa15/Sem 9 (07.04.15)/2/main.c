#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <limits.h>

const int n=100000;
const int threads=1;

int main() {
	srand(time(NULL));
	double A[n],B[n],C[n];
	int i;
	for (i=0;i<n;i++) {
		A[i]=rand();
		B[i]=rand();
	}
	omp_set_num_threads(threads);	
	double time_start=omp_get_wtime();	
	int j;
	#pragma omp parallel
	{
		for (j=omp_get_thread_num()*(n/threads);j<omp_get_thread_num()*(n/threads+1);j++) {
			C[j]=A[j]+B[j];
		}
	}
	printf("%lg\n", omp_get_wtime()-time_start);
	
	return 0;
}
