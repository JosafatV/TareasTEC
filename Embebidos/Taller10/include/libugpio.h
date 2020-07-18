#ifndef libprand
#define libprand

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
int gpioRead(int pin);
int gpioCurrentMode(int pin);

#endif
