#include <stdio.h>
#include <mpi.h>
#include <math.h>

const int N=20000;

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);	
	if (rank==0) {
		double S=0.0;
		int j;
		for (j=1;j<size;j++) {
			double tmpS;
			MPI_Recv(&tmpS, 1, MPI_DOUBLE, j, MPI_ANY_TAG, MPI_COMM_WORLD, NULL);
			S+=tmpS;
		}
		printf("%lf\n", 4.0*S);				
	} else {
		double S=0.0;
		int j;
		const double dh=1.0/N;
		size--;
		rank--;
		for (j=N/size*rank;j<N/size*(rank+1);j++) {
			S+=dh*sqrt(1.0-j*j*dh*dh);
		}
		MPI_Send(&S, 1, MPI_DOUBLE, 0, 11, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
