#include "../include/libprand.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* PATH = "/dev/timer";

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
