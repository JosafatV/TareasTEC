#include "systemc.h"

// SystemC module for milk 
SC_MODULE (milk_mod) {
	sc_in<sc_uint<2>> drink_type;
	sc_in<bool>  enable;
	sc_out<bool> next;
	sc_out<bool> milk_signal;

	void enable_milk () {
		if(prev.read()==1 && enable.read() == 1){
			milk_signal.write(1);
			cout << "@" << sc_time_stamp() << " :: Pouring milk" << milk_signal.read() << endl;
			next.write(1);
		} else {
			milk_signal.write(0);
			next.write(1);
		}
	}

	SC_CTOR(milk_mod) {
		cout << "Executing new m" << endl;
		SC_METHOD(enable_milk);
		sensitive << drink_type << prev << enable;
	}

};