#include "systemc.h"
#include "machine.h"

int sc_main(int argc, char* argv[]) {
	sc_signal<bool> clock;
	sc_signal<bool> enable;
	sc_signal<bool> reset;
	sc_signal<sc_uint<4>> selection;		// drink option
	int i = 0;

	sc_signal<bool> stage0;

	sc_signal<bool> stage1a;
	sc_signal<bool> stage2a;
	sc_signal<bool> stage3a;

	sc_signal<bool> stage1b;
	sc_signal<bool> stage2b;
	sc_signal<bool> stage3b;

	// ================ DUTS ================
	machine dut("expending");


	// ================ TRACE ================
	
	sc_trace_file *wf = sc_create_vcd_trace_file("exor_trace");

	// Dump the desired signals
	sc_trace(wf, enable, "ena");
	sc_trace(wf, reset, "rst");
	sc_trace(wf, selection, "sel");


	// ================ TESTBENCH ================




	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}

	// ================ FINISH ================
    sc_stop();

	cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);

	return 0;
}