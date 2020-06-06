#include <stdio.h>
#include <omp.h>

int cpu_count() {
	int count = omp_get_num_procs();
	printf("There are %d processors available\n", count);
	return count;
}

int main(int argc, char **argv) {

	for (int steps=100; steps<10000; steps*=10) {
		double e = 0.0;
		double known_e = 2.718281828459045;

		double start = omp_get_wtime();
		omp_set_num_threads(cpu_count());
		
		for (int i=1; i<steps; i++){
			double factorial = 1;
			#pragma omp parallel for reduction(*: factorial)
			for (int f=1; f<i; f++) {
				factorial *= f;
			}

			e += 1/factorial;
		}
		//double error_absoluto = known_e-e;
		//double error_relativo_p = error_absoluto/known_e*100;

		printf("Euler's number with %d steps in %f seconds is: %.15f \n \n", steps, omp_get_wtime()-start, e);
	}

	return 0;
}
