# N-Body Gravitational Simulation using parallel C++ codes

# Desrciption :
An N-body gravitational simulation to simulate the movement of planets, stars etc. over an expansive space. These codes contain parallelized versions of the same in OpenMP, MPI and CUDA.

# Include Files

cvector.h : The include file contains the class definition of a vector type to store 3D cartesian coordinates, and associated functions. 

body.h : This contains the class definition for a galactic body and associated functions. This has the function to calculate the acceleration on each body, and this portion would require parallelization.   
