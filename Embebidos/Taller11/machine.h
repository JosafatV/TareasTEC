#include "systemc.h"
#include "milk_mod.h"
#include "water_mod.h"
#include "payment_mod.h"
#include "dispense_mod.h"

SC_MODULE(machine) {
	sc_in<sc_uint<2>> selection;
	sc_out<bool> W, M;//, C, H;

	// Internal modules
	payment_mod pm;
	water_mod wm;
	milk_mod mm;
	dispense_mod dm;

	// Conection signals
	sc_signal<bool> ENA, S0, S1a, S1b;//, S2a, S2b, S3a, S3b;

	SC_CTOR(machine) : pm("PM"), wm("WM"), mm("MM"), dm("DM") {
		pm.drink_type(selection);
		pm.prev(ENA);
		pm.next(S0);

		wm.drink_type(selection);
		wm.prev(S0);
		wm.next(S1a);
		wm.water_signal(W);

		mm.drink_type(selection);
		mm.prev(S0);
		mm.next(S1b);
		mm.milk_signal(M);

		dm.in_a(S1a);
		dm.in_b(S1b);
		dm.enable(ENA);

	}
};