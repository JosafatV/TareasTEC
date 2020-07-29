#include "systemc.h"
#include "payment_mod.h"
#include "dispense_mod.h"

SC_MODULE(machine) {
	sc_in <bool> input;
	sc_out<bool>  W, M;//, C, H;

	// Internal modules
	payment_mod pm;
	dispense_mod dm;

	// Conection signals
	sc_signal<bool> L0, L7;//L1, L2, L3, L4, LS7;

	SC_CTOR(machine) : pm("PM"), dm("DM") {
		pm.prev_state(L0);
		pm.input(input);
		pm.next_state(L0);
		pm.output(W);

		pm.prev_state(L7);
		pm.input(input);
		pm.next_state(L7);
		pm.output(M);


	}
};