#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_matrix(int * Mx, int ROW, int COL) {
	int i = 0;
	int j = 0;
	
    for(i = 0; i < ROW; i++) {
		printf ("| ");
		for (j=0; j < COL; j++) {
			printf ("%d | ", Mx[ROW*i+j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

// Multiplies two square matrix A and B and stores them in C 
void matrix_mul (int* A, int* B, int* C, int ROW, int COL) {
	int C_temp = -1;
	for(int i = 0; i < ROW; i++) {
		for (int j=0; j < COL; j++) {
			C[i*ROW+j] = 0;
			for (int k=0; k < COL; k++) {
				C[i*ROW+j] += A[i*ROW+k] * B[k*COL+j];
			}
		}
	}
}


int main () {
	int i, j;
	const int ROW = 10000;
	const int COL = ROW;
	int val = 10;
	
    int *A = (int*)malloc(sizeof(int)*ROW*COL);
    int *B = (int*)malloc(sizeof(int)*ROW*COL);
    int *C = (int*)malloc(sizeof(int)*ROW*COL);

    // Init the vectors 
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++){
			A[ROW*i+j] = i+1;
			B[ROW*i+j] = i*4+j;
			val++;
		}
	}
	
	//print_matrix(A, ROW, COL);
	//print_matrix(B, ROW, COL);

	double start = omp_get_wtime();
	
	matrix_mul(A,B,C, ROW, COL);

	printf("+++ MX_MUL_SERIAL with SIZE %dx%d took: %.7f +++ \n", ROW,COL, omp_get_wtime()-start);
 	
	//print_matrix(C, ROW, COL);

	
	return 0;
}
