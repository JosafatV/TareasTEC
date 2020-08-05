#include "systemc.h"

void deploy_state::update_status () {
	int my_status = 0;

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