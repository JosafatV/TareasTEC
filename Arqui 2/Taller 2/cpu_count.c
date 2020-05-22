#include <stdio.h>
#include <omp.h>

int cpu_count() {
	int count = omp_get_num_procs();
	printf("There are %d processors available\n", count);
	return count;
}


int main(int argc, char **argv) {
	int	a = cou_count()
	return 0;
}
