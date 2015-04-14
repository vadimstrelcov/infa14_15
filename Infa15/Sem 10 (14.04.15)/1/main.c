#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
	int rank, size;
	MPI_Init(&argc, &argv);
	int a=156, b=0, i;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("I'm %d / %d\n",rank, size);
	if (rank==0) {
		for (i=1;i<size;i++) {
			MPI_Send(&a, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	printf("My b is %d \n",b);
	MPI_Finalize();
	return 0;
}
