#include <cstdio>
#include <iostream>
#include <cmath>
#include <mpi.h>

#include "Polygon.h"

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    double start_time, end_time;
    start_time = MPI_Wtime();

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double h_t=0.001;
    int steps=1000, n_count=100;
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
    Polygon polygon("tests/input5.txt", 1, 1000, 1000, h_t);
    polygon.get_partition();

    for(int count=0; count<n_count; count++){
        polygon.solve(count*steps*h_t, steps, 1);
        //printf("> %d\n", count);
    }

    MPI_Barrier(MPI_COMM_WORLD);

    end_time = MPI_Wtime();
    if(rank == 0) printf("Finished. Time: %.2f s\n", end_time-start_time);
    MPI_Finalize();
    return 0;
}
