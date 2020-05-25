#include <stdio.h> 
#include <stdlib.h> 

typedef struct package {
		int id;
		float weight;
		short side;		// 0: a, 1: b
		short priority; // 0: norm, 1: urge, 2: rads
		short status;	// 0: not ready, 1: ready to send, 2: in transit, 3: delivered
		short band;		
	} package_t;

const char* read_path = "/home/josav09/Documents/C tests/fileReader/readme.txt";
const char* write_path = "/home/josav09/Documents/C tests/fileReader/cpu.log";

void read_file (char* data) {
	FILE *fp;
	fp = fopen(read_path, "r"); // read mode

	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	char str[128];
	char* value;
	fgets(str, 128, fp);
	puts(str);
	//printf("%s\n", str);
	fclose(fp);
    data = &str[0];
}

void write_log (char* data) {
	FILE *fp;
	char* newline = "\n";
	fp = fopen(write_path, "a"); // append mode

	if (fp == NULL) {
	  perror("Error while opening the file.\n");
	  exit(EXIT_FAILURE);
	}

	fprintf(fp, "%s", data);
	fprintf(fp, "%s", newline);

	fclose(fp);
}


int main () {
	char* read;
	read_file(read);
	printf("Read: %s", read);
	write_log(read);
   
   return 0;
}



