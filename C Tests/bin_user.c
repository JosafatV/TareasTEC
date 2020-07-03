
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	printf("Hello World!\n");
	
	// test << 
	int a = 4;
	int b = a << 2;
	printf("b is: %d \n", b);
	
	// test buckets w if | else if | else
	if (a<2) {
		printf("a<2\n");
	}
	else if(a<8) {
		printf("a >=2 AND a < 8\n");
	}
	else {
		printf("a >= 8\n");
	}
	
	// test masks
	int src = 1869; // 011 101 001 101
	int mask = 7; // isolate 3 bits
	mask = mask << 3*3;
	printf("mask is: %d\n", mask);
	int ret = src & mask;
	ret = ret >> 3*3;
	printf("ret is: %d\n", ret);
	
	int pin = 3;
	int d = 1 << 3;
	printf("d is: %d\n", d);
	
	return 0;
}
