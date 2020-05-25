#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
	
    srand(time(0));
	for (int i = 0; i<10; i++){
		uint8_t a = rand()%256;
		printf("A is: %d \n", a);
	}
	
	uint16_t b = rand()%65536;
	printf("B is: %d \n", b);
	
	uint16_t c = rand()%65536+1;
	printf("C is: %d \n", c);
	
	return 0;
}

