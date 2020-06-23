#include <stdio.h>
#include <libprand.h>

int main() {
	printf("+++ Initializing +++\n");
	chrono();

// Check timer is not running
	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);

	start_timer();

	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);
	
	stop_timer();

	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);
	printf("  Generated: %d \n", generate_num());
	usleep(500);	

	printf("+++ Terminating +++");
	chrono();

    return 0;
}
