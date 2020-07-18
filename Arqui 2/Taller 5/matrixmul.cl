// Josafat Vargas 17/07
__kernel void matrixmul (__global const int* A, __global const int* B, __global const int* C {

	#define 
	
	// identify each work item executing the kernel
    int row = get_global_id(0);
    int col = get_global_id(1);
    int Cres = 3;

	// Do the operation
    for(int i = 0;i< 4; i++) {
		res = += a[row*4 + i] * b[i*4 + col];
		c[row*4+col] = res;
	}

}
