#include "hash.h"

__global__ void crack_kernel(char *passwords)
{
	// calculate the row index of the Pd element and M
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    // calculate the column index of Pd and N
    int col = blockIdx.x * blockDim.x + threadIdx.x;

}
