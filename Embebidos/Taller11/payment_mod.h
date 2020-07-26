#include "systemc.h"

//SystemC module for payment
SC_MODULE (payment_mod) {
	sc_in<sc_uint<2>> drink_type;
	sc_in<bool> prev;
	sc_in<bool> enable;
	sc_out<bool> next;

	void choose_drink () {

		int type = drink_type.read().range(3,2);

		if (prev.read() == 1) {
			next.write(type);
		}
	}

	SC_CTOR (payment_mod) {
		cout << "Executing new payment_mod" << endl;
		SC_METHOD(choose_drink);
		sensitive << drink_type << enable;
	}
};