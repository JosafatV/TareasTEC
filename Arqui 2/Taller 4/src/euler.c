#include <stdio.h>
#include <omp.h>

int cpu_count() {
	int count = omp_get_num_procs();
	printf("There are %d processors available\n", count);
	return count;
}

int main(int argc, char **argv) {

	for (int steps=100; steps<10000; steps*=10) {
		double e = 1.0;
		double known_e = 2.718281828459045;
		double factorial = 1;

		double start = omp_get_wtime();
		
		for (int i=1; i<steps; i++){
			factorial *= i;
			e += 1/factorial;
		}
		//double error_absoluto = known_e-e;
		//double error_relativo_p = error_absoluto/known_e*100;

		printf("Euler's number with %d steps in %f seconds is: %.15f \n", steps, omp_get_wtime()-start, e);
	}

	return 0;
}
