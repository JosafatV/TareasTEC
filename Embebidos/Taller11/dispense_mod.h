#include "systemc.h"

// SystemC module for water 
SC_MODULE (dispense_mod) {
	sc_in<bool> enable;
	sc_in<bool>	in_a;
	sc_in<bool> in_b;
	sc_out<bool> out;

	void dispense () {
		if (in_a.read()==1 || in_b.read()==1) {
			//door_signal.write(1);
			//cout << "@" << sc_time_stamp() << " :: Opening serving hatch" << door_signal.read() << endl;
			cout << "@" << " :: Opening serving hatch" << endl;
			out.write(0);
		} else {
			if (enable.read() == 1) {
				out.write(1);
			}
				cout << "Machine ready!" << endl;
				// Wait for input 
				out.write(0);
		}
	}

	SC_CTOR(dispense_mod) {
		cout << "Executing new" << endl;
		SC_METHOD(dispense);
		sensitive << in_a << in_b << enable;
	}

};