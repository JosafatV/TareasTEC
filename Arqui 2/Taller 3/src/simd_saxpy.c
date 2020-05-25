#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include "../include/linked_list.h"

int cpu_count() {
	int count = omp_get_num_procs();
	printf(" +++ %d processors are available +++\n", count);
	return count;
}

int main () {
	int alpha = rand()%21+5;
	int length = vector_len;	// Define in linked_list.h
	Node_t* x = NULL;
	Node_t* y = NULL;
	Node_t* z = NULL;

	srand(time(NULL));
	
	// Create vectors in memory and intialize variables
	for (int i = 0; i<length; i++) {
		push_back(&x, rand() % 101);
		push_back(&y, rand() % 101);
		push_back(&z, 0);
	}
	
	double start = omp_get_wtime();

	// CODE GOES HERE //////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////////////////

	printf("Execution took %f seconds, vector length: %d \n", omp_get_wtime()-start, length);

	return 0;
}
