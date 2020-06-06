#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include "../include/linked_list.h"

int main () {
	int alpha = rand()%21+5;
	int length = 10000;
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

	//printf("X is: "); print_list(x);
	//printf("Y is: "); print_list(y);

	double start = omp_get_wtime();

	// Compute
	for (int i = 0; i<length; i++) {
		int rez = get_at(x, i)*alpha + get_at(y, i);
		set_at(z, i, rez);
	}

	//printf("Z is: "); print_list(z);
	printf("Execution took %f seconds, vector length: %d \n", omp_get_wtime()-start, length);

	return 0;
}
