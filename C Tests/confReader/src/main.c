#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/libconfReader.h"

const char* path_to_config = "../config/local.conf";

int main() {
    //int buffer_size=512;
    //char buffer[buffer_size];
    //char dateBuffer[buffer_size];

    // Prepare configuration struct
    config_t* local_conf = get_config(path_to_config); //Read the file

    //Copies data to constats
    const int ID = local_conf->ID;
	const int val = local_conf->val;
    const int t = local_conf->t;

	// Debug read data
    print_config(local_conf);
    
    return EXIT_SUCCESS;
}
