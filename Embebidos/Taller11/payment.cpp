#include "systemc.h"

// SystemC module for odd
SC_MODULE (payment_state) {
	sc_in<bool> input;
	sc_out<bool> output;
	sc_out<sc_uint<4>> out_status;
	
	sc_uint<4> status;

	void update_status () {
		int my_status = 7;

		// Update status if input is 1
		if (input.read() == 1) {
			switch (status) {
				case 0:
					status = 1;
					out_status.write(status);
					break;
				case 1:
					status = 3;
					out_status.write(status);
					break;
				case 2:
					status = 3;
					out_status.write(status);
					break;
				case 7:
					status = 0;
					out_status.write(status);
					break;			
				default:
					status = 7;
					out_status.write(status);
					break;
				}
		// Update status if input is 0
		} else {
			switch (status) {
				case 0:
					status = 2;
					out_status.write(status);
					break;
				case 1:
					status = 4;
					out_status.write(status);
					break;
				case 2:
					status = 4;
					out_status.write(status);
					break;		
				default:
					status = 7;
					out_status.write(status);
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

	SC_CTOR(payment_state) {
		cout << "Added machine state 7" << endl;
		SC_METHOD(update_status);
		sensitive << input;
	}

};