#include "systemc.h"

void payment_mod::fsm_status () {
		int my_status = 0;
		int status = (int) prev_state.read();

		// Update status if input is 1
		if (input.read() == 1) {
			switch (status) {
				case 0:
					next_state.write(1);
					break;
				case 1:
					next_state.write(3);
					break;
				case 2:
					next_state.write(3);
					break;
				case 7:
					next_state.write(0);
					break;			
				default:
					next_state.write(7);
					break;
				}
		// Update status if input is 0
		} else {
			switch (status) {
				case 0:
					next_state.write(2);
					break;
				case 1:
					next_state.write(4);
					break;
				case 2:
					next_state.write(4);
					break;		
				default:
					next_state.write(7);
					break;
				}
		}

		if (prev_state.read() == my_status) {
			// It's me! Tell the world!
			cout << "Machine is in state %d" << endl;
			output.write(1);
		} else {
			output.write(0);
		}
	}
