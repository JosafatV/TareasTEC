#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include "../include/arm_neon.h"
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

	int32x4_t simd_alpha;
	vsetq_lane_s32(alpha, simd_alpha, 2); // You must initialize them using one of the load intrinsics.
	vsetq_lane_s32(alpha, simd_alpha, 0); // Assume the same behavior as in SSEx

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

		int32x4_t simd_x;
		vsetq_lane_s32(get_at(x, i+1), simd_x, 2);
		vsetq_lane_s32(get_at(x, i), simd_x, 0);

		int32x4_t ax = vmulq_u32(simd_x, simd_alpha);

		int32x4_t simd_y;
		vset_lane_s32(get_at(y, i+1), simd_y, 2);
		vset_lane_s32(get_at(y, i), simd_y, 0);

		int32x4_t res = vaddq_s32(ax, simd_y);

		set_at(z, i+1, vget_lane_s32(res, 2));
		set_at(z, i, vget_lane_s32(res, 0));
	}

	#pragma omp single
	//printf("Z is: "); print_list(z);
	printf("Execution took %f seconds, vector length: %d \n", omp_get_wtime()-start, length);

	return 0;
}
