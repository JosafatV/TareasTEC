#include <sys/mman.h> //mmap
#include <err.h> //error handling
#include <fcntl.h> //file ops
#include <unistd.h> //usleep
#include <stdio.h> //printf
#include <libugpio.h>

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

	// Static base
static unsigned GPIO_BASE = 0x3f200000;

	// Regs pointers
volatile unsigned int * gpfsel0;
volatile unsigned int * gpfsel1;
volatile unsigned int * gpfsel2;
volatile unsigned int * gpset0;
volatile unsigned int * gpset1;
volatile unsigned int * gpclr0;
volatile unsigned int * gpclr1;
volatile unsigned int * gplev0;
volatile unsigned int * gplev1;

	// Function prototypes
void gpioInitPtrs();
void gpioSetMode(int mode, int pin);
void gpioWrite(unsigned char bit, int pin);
int gpioRead(int pin);
int gpioCurrentMode(int pin);

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

	// Set reg pointers for event detect status
	gplev0 = gpfsel0 + 0xD; // offset 0x34
	gplev1 = gpfsel0 + 0xE; // offset 0x38

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

/** Reads the status of a specific GPIO pin
 * \param pin which pin to read (check datasheet, not physical) 
 */
int gpioRead(int pin){
	// create mask to isolate bit
	int mask = 0;
	int ret = 0;
	if (pin<32){
		mask = 1 << pin;
		ret = (int) gplev0 & mask;
	} else {
		mask = 1 << 32-pin;
		ret = (int) gplev1 & mask;
	}

	if (ret>0){
		return 1;
	} else {
		return 0;
	}
}

/** Return the value of the current mode in the selected pin
 * \param pin the pin that is being checked
 */
int gpioCurrentMode (int pin) {
	int mode = 0;
	int mask = 7;
	if (pin < 10) {
		mask = mask << pin*3;
		printf("mask is: %d\n", mask);
		mode = *gpfsel0 & mask;
		printf("isolated is: %d\n", mode);
		mode = mode >> pin*3;
		printf("mode is: %d\n", mode);
	} else if (pin < 20) {
		mask = mask << (pin-10)*3;
		mode = *gpfsel1 & mask;
		mode = mode >> (pin-10)*3;
	} else if (pin < 30) {
		mask = mask << (pin-20)*3;
		mode = *gpfsel2 & mask;
		mode = mode >> (pin-20)*3;
	} else {
		printf("Not yet implemented\n");
	}
		// output-print mode
	switch (mode) {
	case INPUT_MODE:
		printf("Pin %d is in input_mode\n", pin);
		return 0;
		break;
	case OUTPUT_MODE:
		printf("Pin %d is in output_mode\n", pin);
		return 1;
		break;
	case ALT0_MODE:
		printf("Pin %d is in alt_mode_0\n", pin);
		return 2;
		break;
	case ALT1_MODE:
		printf("Pin %d is in alt_mode_1\n", pin);
		return 3;
		break;
	case ALT2_MODE:
		printf("Pin %d is in alt_mode_2\n", pin);
		return 4;
		break;
	case ALT3_MODE:
		printf("Pin %d is in alt_mode_3\n", pin);
		return 5;
		break;
	case ALT4_MODE:
		printf("Pin %d is in alt_mode_4\n", pin);
		return 6;
		break;
	case ALT5_MODE:
		printf("Pin %d is in alt_mode_5\n", pin);
		return 7;
		break;
	default:
		printf("Something went wrong (Pin %d)\n", pin);
		return -1;
		break;
	}
}