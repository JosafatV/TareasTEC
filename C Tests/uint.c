
#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>

int main () {
	
	printf("This tests uint_t data types \n");
	
	uint8_t a = 0;
	uint8_t b = 1;
	
	printf ("a is: %d\n", a);
	
	for (uint8_t i; i<255; i++){
		a = a + b;
		printf ("a is: %d\n", a);
	}
	
	a = a + b;
	printf ("a is: %d\n", a);
	
	
	
	
	return 0;
	
}
