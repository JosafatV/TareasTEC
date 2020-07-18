#include <unistd.h> //usleep
#include <stdio.h> //printf
#include <libugpio.h>

int main(int argc, char const *argv[]) {
		// map memory
	gpioInitPtrs();
	
		// setup
	gpioSetMode(OUTPUT_MODE, 2);
	gpioSetMode(OUTPUT_MODE, 17);
	gpioSetMode(OUTPUT_MODE, 22);
	gpioSetMode(OUTPUT_MODE, 27);
	gpioSetMode(INPUT_MODE, 3);
	gpioSetMode(INPUT_MODE, 4);
	gpioSetMode(INPUT_MODE, 5);
	gpioSetMode(INPUT_MODE, 6);
	usleep(500000); // turn to-look-delay

	gpioCurrentMode(2);
	gpioCurrentMode(17);
	gpioCurrentMode(22);
	gpioCurrentMode(27);
	gpioCurrentMode(3);
	gpioCurrentMode(4);
	gpioCurrentMode(5);
	gpioCurrentMode(5);

		// toggle GPIO17 - GREEN
	gpioWrite(HI_VAL, 17);
	usleep(1000000);
	gpioWrite(LO_VAL, 17);

		// toggle GPIO27 - YELLOW
	gpioWrite(HI_VAL, 27);
	usleep(1000000);
	gpioWrite(LO_VAL, 27);

		// toggle GPIO2 - RED
	gpioWrite(HI_VAL, 2);
	usleep(1000000);
	gpioWrite(LO_VAL, 2);

		// light GPIO - BLUE
	gpioWrite(HI_VAL, 22);
	usleep(1000000);
	gpioWrite(LO_VAL, 22);

		// read test
	int read_3 = -1;
	int read_4 = -1;
	int read_5 = -1;
	int read_6 = -1;
	printf (" pin 3 | pin 4 | pin 5 | pin 6 \n");
	while (1) {
		read_3 = gpioRead(3);
		read_4 = gpioRead(4);
		read_5 = gpioRead(5);
		read_6 = gpioRead(6);
		usleep(1000000);
		printf ("   %d   |   %d  |   %d  |   %d   \n", read_3, read_4, read_5, read_6);
	}

	return 0;
}
