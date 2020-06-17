#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <omp.h>
#include <math.h>

int cpu_count() {
	int count = omp_get_num_procs();
	printf("There are %d processors available\n", count);
	return count;
}

double calculate_error (double obt) {
	double known = 0.577215664901532;
	double error_absoluto = known-obt;
	double error_relativo_p = error_absoluto/known*100;
	return error_relativo_p;
}

// Calculate harmonic number: Hn. The infinite sum for Hn - ln(n) converges to the Euler-Mascheroni cte
int main () {
	omp_set_num_threads(cpu_count());
	for (long n=1000; n<10000000000; n*=10){
		double start = omp_get_wtime();
		double hn = 0;
		
		// Compute harmonic series
		#pragma omp parallel for reduction (+: hn)
		for (int i = 1; i<=n; i++) {
			hn += (double) 1/i;
		}
		
		double e_m = -log(n)+hn;
		double err = calculate_error(e_m);

		printf("Euler-Mascheroni cosntant with %ld iterations error is: %.15f\n", n, err);
		printf("Execution took %f seconds\n", omp_get_wtime()-start);
	}
	return 0;
}
