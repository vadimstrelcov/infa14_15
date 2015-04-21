#include <omp.h>
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int mpi_rank;
    MPI_Init(&argc, &argv);
    #pragma omp parallel
    {
	MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
	printf("My node: %d, my thread: %d\n", mpi_rank, omp_get_thread_num());
    }
    MPI_Finalize();
    return 0;
}
