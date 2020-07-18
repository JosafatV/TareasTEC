#include <stdio.h>
#include <stdlib.h>

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
	const int ROW = 4;
	const int COL = 4;
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
	
	print_matrix(A, ROW, COL);
	print_matrix(B, ROW, COL);
	
	matrix_mul(A,B,C, ROW, COL);
	
	print_matrix(C, ROW, COL);

	
	return 0;
}
