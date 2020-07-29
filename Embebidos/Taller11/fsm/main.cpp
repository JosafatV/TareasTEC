#include "systemc.h"
#include "machine.h"

int sc_main(int argc, char* argv[]) {
	sc_signal<bool> clock;
	sc_signal<bool> input;
	int i = 0;

	sc_signal<bool> output_s0;
	sc_signal<bool> output_s7;

	// ================ DUTS ================
	machine dut("expending");

	// ================ TRACE ================
	
	sc_trace_file *wf = sc_create_vcd_trace_file("fsm2_trace");

	// Dump the desired signals
	sc_trace(wf, input, "input");
	sc_trace(wf, output_s0, "output_s0");
	sc_trace(wf, output_s7, "output_s7");


	// ================ TESTBENCH ================

	input.write(0);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
	input.write(0);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
	input.write(1);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
	input.write(0);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
	input.write(1);
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