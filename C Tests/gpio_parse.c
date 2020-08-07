#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char* read_path = "./led_status.txt";
const char* write_path = "./btn_status.txt";
int half_sec = 500000;

// GPIO pin definitions
short red_led = 17;
short yel_led = 27;
short grn_led = 22;

void update_leds () {
	FILE *fp;
	char str[16];
	char* value;
	while (1) {
		fp = fopen(read_path, "r"); // read mode

		if (fp == NULL) {
			perror("Error while opening the r_file.\n");
			exit(EXIT_FAILURE);
		}

		fgets(str, 16, fp);
		//puts(str);
		printf("%d:%d:%d\n", str[0]-48,str[2]-48,str[4]-48);
		fclose(fp);
		usleep(half_sec);
	}
    
}

int main() {
	
	/* init pins
	pinMode(red_led, OUTPUT);
	pinMode(yel_led, OUTPUT);
	pinMode(grn_led, OUTPUT);
	pinMode(pin_btn, INPUT);
	*/

	// Control GPIO
	update_leds();

   return 0;
}
