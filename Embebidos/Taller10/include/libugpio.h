#ifndef libprand
#define libprand

void gpioInitPtrs();
void gpioSetMode(int mode, int pin);
void gpioWrite(unsigned char bit, int pin);
int gpioRead(int pin);
int gpioCurrentMode(int pin);

#endif
