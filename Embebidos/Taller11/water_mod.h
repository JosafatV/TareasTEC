#include "systemc.h"

// SystemC module for water 
SC_MODULE (water_mod) {
	sc_in<sc_uint<2>> drink_type;
	sc_in<bool>  enable;
	sc_out<bool> next;
	sc_out<bool> water_signal;

	void enable_water () {
		if(prev.read()==0 && enable.read() == 1){
			water_signal.write(1);
			cout << "@" << sc_time_stamp() << " :: Pouring water" << water_signal.read() << endl;
			next.write(1);
		} else {
			water_signal.write(0);
			next.write(1);
		}
	}

	SC_CTOR(water_mod) {
		cout << "Executing new w" << endl;
		SC_METHOD(enable_water);
		sensitive << drink_type << prev << enable;
	}

};