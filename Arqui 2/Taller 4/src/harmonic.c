#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include "../include/linked_list.h"

int cpu_count() {
	int count = omp_get_num_procs();
	printf("There are %d processors available\n", count);
	return count;
}

// Calculate harmonic number: Hn. The infinite sum for Hn - ln(n) converges to the Euler-Mascheroni cte
int main () {
	int n = 200;
	
	double start = omp_get_wtime();
	double hn = 0;
	
	// Compute harmonic series
	for (int i = 1; i<=n; i++) {
		hn += 1/i;
	}
	double e_m = -log(n)+hn;

	printf("Harmonic series with %d iterations is: %.15f\n", n, hn);
	printf("Natural logarithm is: %.15f\n", -log(n));
	printf("Euler-Mascheroni cosntant with %d iterations is: %.15f\n", n, e_m);
	printf("Execution took %f seconds\n", omp_get_wtime()-start);

	return 0;
}
