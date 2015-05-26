HEAT_EQUATION_PARALLEL
============
main.cpp Polygon.cpp Polygon.h
============
mpiCC main.cpp Polygon.cpp -O2 -o main

mpirun -np 4 ./main

