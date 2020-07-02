#include <sys/mman.h> //mmap
#include <err.h> //error handling
#include <fcntl.h> //file ops
#include <unistd.h> //usleep
#include <stdio.h> //printf

// Constants
#define INPUT_MODE 0
#define OUTPUT_MODE 1
#define ALT0_MODE 4
#define ALT1_MODE 5
#define ALT2_MODE 6
#define ALT3_MODE 7
#define ALT4_MODE 3
#define ALT5_MODE 2

#define HI_VAL 1
#define LO_VAL 0

void gpioInitPtrs();
void gpioSetMode(int mode, int pin);
void gpioWrite(unsigned char bit, int pin);

	// Static base
static unsigned GPIO_BASE = 0x3f200000;

	// Regs pointers
volatile unsigned int * gpfsel0;
volatile unsigned int * gpfsel1;
volatile unsigned int * gpfsel2;
volatile unsigned int * gpset0;
volatile unsigned int * gpclr0;
volatile unsigned int * gpset1;
volatile unsigned int * gpclr1;

	// Function prototypes
void gpioInitPtrs();
void gpioSetMode(int mode, int pin);
void gpioWrite(unsigned char bit, int pin);

// Initialize pointers: performs memory mapping, exits if mapping fails
void gpioInitPtrs() {
	int fd = -1;
	//Loading /dev/mem into a file
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
		err(1, "Error opening /dev/mem");

	//Mapping GPIO base physical address
	gpfsel0 = (unsigned int*) mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE); // reg with pins 2,3,4,5,6
			
		//Check for mapping errors
	if (gpfsel0 == MAP_FAILED || gpfsel1 == MAP_FAILED || gpfsel2 == MAP_FAILED)
		errx(1, "Error during mapping GPIO");

	// Set reg pointers for function select
	gpfsel1 = gpfsel0 + 0x1; // offset 0x04
	gpfsel2 = gpfsel0 + 0x2; // offset 0x08

	// Set reg pointers for output set
	gpset0 = gpfsel0 + 0x7; // offset 0x1C
	gpset1 = gpfsel0 + 0x8; // offset 0x20

	// Set reg pointers for output clear
	gpclr1 = gpfsel0 + 0xB; // offset 0x2C
	gpclr0 = gpfsel0 + 0xA; // offset 0x28

}

/** Set GPIO at pin as mode input or output
 * \param mode: gpio mode: use INPUT_MODE or OUTPUT_MODE
 * \param pin: which pin to write (check datasheet, not physical)
 */
void gpioSetMode(int mode, int pin) {
	// offset the bit to chosen the pin
	// write to correct gpfsel (10 pins per gpfsel)
	if (pin < 10) {
		mode = mode << pin*3; 
		*gpfsel0 = *gpfsel0 | mode;
	} else if (pin < 20) {
		mode = mode << (pin-10)*3;
		*gpfsel1 = *gpfsel1 | mode;
	} else if (pin < 30) {
		mode = mode << (pin-20)*3;
		*gpfsel2 = *gpfsel2 | mode;
	} else {
		printf("Not yet implemented\n");
	}
}

/** Writes to a specific GPIO pin
 * \param bit the value to set the pin. Use HI_VAL or LO_VAL
 * \param pin which pin to set (check datasheet, not physical) 
 */
void gpioWrite(unsigned char bit, int pin) {
	int mode = 1;
	if (pin < 32) {
		mode = mode << pin;
		if (bit) *gpset0 = mode; //sets bit
		else *gpclr0 = mode; //clears bit
	} else {
		mode = mode << (pin-32);
		if (bit) *gpset1 = mode; //sets bit
		else *gpclr1 = mode; //clears bit
	}
}

int main(int argc, char const *argv[]) {
		// map memory
	gpioInitPtrs();

		// setup
	gpioSetMode(OUTPUT_MODE, 2);
	gpioSetMode(OUTPUT_MODE, 17);
	gpioSetMode(OUTPUT_MODE, 27);
	usleep(500000); // turn to-look-delay

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

	return 0;
}
