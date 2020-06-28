// Josafat Vargas 28/06
__kernel void saxpy (__global const int* Z, __global const int* A, __global const int* X, __global const int* Y) {

	// Get the index of the current element to be processed
    int i = get_global_id(0);

	// Do the operation
	Z[i] = A[i] * X[i] + Y[i];

}