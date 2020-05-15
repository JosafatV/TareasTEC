
#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
	int count = omp_get_num_procs();
	//int count = omp_get_thread_num();
	printf("There are %d processors available\n", count);
	return 0;
}
