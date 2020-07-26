#include "systemc.h"
#include "nand.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> ASig, BSig, FSig;
	sc_signal<bool> clock;
	int i = 0;

	nand2 DUT("and");
	DUT.A(ASig);
	DUT.B(BSig);
	DUT.F(FSig);

	sc_start(1,SC_NS);

	// Open VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("nand_trace");
	// Dump the desired signals
	sc_trace(wf, ASig, "a");
	sc_trace(wf, BSig, "b");
	sc_trace(wf, FSig, "f");


	ASig.write(false);
	BSig.write(false);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
    ASig.write(false);
    BSig.write(true);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
    //wait();
    ASig.write(true);
    BSig.write(false);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
    //wait();
    ASig.write(true);
    BSig.write(true);
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1,SC_NS);
		clock = 1; 
		sc_start(1,SC_NS);
	}
    //wait();
    sc_stop();

	cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);

	return 0;

}