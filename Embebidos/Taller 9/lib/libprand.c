#include <libprand.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int chrono_flag = 0;
double start_time = 0;
char* PATH = "/dev/timer";

/** Toggle an execution timer. Call to start timer or to stop and print exe time
*/
void chrono () {
	double current_time = omp_get_wtime();
	// Running, set start_time
	if (chrono_flag) {
		chrono_flag = 0;
		printf("Execution time is: %.6f\n", current_time-start_time);
		start_time=0;
	} else {
		chrono_flag = 1;
		start_time = current_time;
		printf("Timer started\n");
	}
}

/** Writes a int to a file, overwritting the existing file
 * \param data the data to be written. An int
 * \param write_path the path to the file
 */
void write_int(int data) {
	FILE *fp;
	fp = fopen(PATH, "w"); // append mode

	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d", data);
	fclose(fp);
}

/** Generate a pseudo-random number 
 */
int generate_num () {
	FILE *file = fopen(PATH, "r");
	char line[256];

	if (file == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	fgets(line, sizeof(line), file);
	int read = atoi(line);

	fclose(file);
	return read;
}

void start_timer () {
	//system("echo -n 1 > /dev/timer");
	write_int(1);
}

void stop_timer() {
	//system("echo -n 0 > /dev/timer");
	write_int(0);
}