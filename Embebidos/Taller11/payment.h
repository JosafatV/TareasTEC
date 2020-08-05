#include "systemc.h"

void payment_state::update_status () {
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