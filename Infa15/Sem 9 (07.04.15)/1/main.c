#include <stdio.h>
#include <omp.h>

int main() {
	omp_set_num_threads(16);
	#pragma omp parallel
	{
		printf("Hello, world. I'm thread number = %d (%d)\n", omp_get_thread_num(), omp_get_num_threads());
	}
	return 0;
}
