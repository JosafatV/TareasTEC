#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include <emmintrin.h>
#include <smmintrin.h>
#include "../include/linked_list.h"

int cpu_count() {
	int count = omp_get_num_procs();
	printf(" +++ %d processors are available +++\n", count);
	return count;
}

int main () {
	int alpha = rand()%21+5;
	int length = 20000;
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

	omp_set_num_threads(cpu_count());
	double start = omp_get_wtime();
	__m128i simd_alpha = _mm_set_epi32(0, alpha, 0, alpha);

	// Create padding for the vectors
	if (length%4) {
		for (int i=0; i<(4-length%4); i++) {
			push_back(&x, 0);
			push_back(&y, 0);
			push_back(&z, 0);
		}
	}

	// Compute saxpy
	#pragma omp parallel for shared(alpha, length)
	for (int i = 0; i<length; i+=2) {
		__m128i simd_x = _mm_set_epi32(0, get_at(x, i), 0, get_at(x, i+1));
		__m128i ax = _mm_mul_epu32(simd_x, simd_alpha); 
		__m128i simd_y = _mm_set_epi32(0, get_at(y, i), 0, get_at(y, i+1));
		__m128i res = _mm_add_epi32(ax, simd_y);

		set_at(z, i, _mm_extract_epi32(res, 2));
		set_at(z, i+1, _mm_extract_epi32(res, 0));
	}

	#pragma omp single
	//printf("Z is: "); print_list(z);
	printf("Execution took %f seconds, vector length: %d \n", omp_get_wtime()-start, length);

	return 0;
}
