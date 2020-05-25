#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

typedef struct {
	uint8_t bedroom;
	uint8_t bathroom;
	uint8_t hallway;
	uint8_t kitchen;
	uint8_t studio;
} devices_t;

int main () {
	char * query = "1:0:1:0:1";
	char str[80];
	strcpy(str, query);
	const char s[2] = ":";
	char *token;
	devices_t leds;
	token = strtok(str, s);
	leds.bedroom = atoi(token);
	token = strtok(NULL, s);
	leds.bathroom = atoi(token);
	token = strtok(NULL, s);
	leds.hallway = atoi(token);
	token = strtok(NULL, s);
	leds.kitchen = atoi(token);
	token = strtok(NULL, s);
	leds.studio = atoi(token);
	
	printf("led bedroom: %d\n", leds.bedroom);
	printf("led bathroom: %d\n", leds.bathroom);
	printf("led hallway: %d\n", leds.hallway);
	printf("led kitchen: %d\n", leds.kitchen);
	printf("led studio: %d\n", leds.studio);
	
	
   
   
   return(0);
}

