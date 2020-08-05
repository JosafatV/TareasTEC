#include "systemc.h"

// SystemC module for odd
SC_MODULE (coffee_state) {
	sc_in<bool> input;
	sc_out<bool> output;
	sc_uint<4> status;

	void update_status () {
		int my_status = 3;

		// Update status if input is 1
		if (input.read() == 1) {
			switch (status) {
				case 0:
					status = 1;
					break;
				case 1:
					status = 3;
					break;
				case 2:
					status = 3;
					break;
				case 7:
					status = 0;
					break;			
				default:
					status = 7;
					break;
				}
		// Update status if input is 0
		} else {
			switch (status) {
				case 0:
					status = 2;
					break;
				case 1:
					status = 4;
					break;
				case 2:
					status = 4;
					break;		
				default:
					status = 7;
					break;
				}
		}

		if (status == my_status) {
			// It's me! Tell the world!
		cout << "Machine is in state " << my_status << endl;
			output.write(1);
		} else {
			output.write(0);
		}
	}

	SC_CTOR(coffee_state) {
		cout << "Added machine state 3" << endl;
		SC_METHOD(update_status);
		sensitive << input;
	}

};