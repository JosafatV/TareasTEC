#include "systemc.h"
#include "deploy.cpp"
#include "payment.cpp"
#include "coffee.cpp"
#include "choco.cpp"
#include "milk.cpp"
#include "water.cpp"

int sc_main (int argc, char* argv[]) {
  sc_signal<bool>   clock;
  sc_signal<bool>   insig;
  sc_signal<bool>   outD, outP, outM, outW, outCh, outCo;
  sc_signal<sc_uint<4> > state_out;
  
  int i = 0;
  // Connect the DUT
  deploy_state ds("DEPL");
  	ds.input(insig);
    ds.output(outD);

  payment_state ps("PAYM");
    ps.input(insig);
	ps.output(outP);
    ps.out_status(state_out);

  milk_state ms("MILK");
  	ms.input(insig);
    ms.output(outM);
    
  water_state ws("WATR");
  	ws.input(insig);
    ws.output(outW);
    
  choco_state hs("CHOC");
  	hs.input(insig);
    hs.output(outCh);
    
  coffee_state cs("CFFE");
  	cs.input(insig);
    cs.output(outCo);

    sc_start(1,SC_NS);

  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("fsm_trace");

  // Dump the desired signals
  sc_trace(wf, clock, "clock");
  sc_trace(wf, insig, "input");
  sc_trace(wf, outD, "deploy");
  sc_trace(wf, outP, "payment");
  sc_trace(wf, outM, "milk");
  sc_trace(wf, outW, "water");
  sc_trace(wf, outCh, "choco");
  sc_trace(wf, outCo, "coffee");
  sc_trace(wf, state_out, "fsm_state");

  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 0;  // Assert liquid type ***
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 1;  // Assert flavour ***
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 0;  // Finish serving
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 1;  // Assert payment
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
    cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 0;  // Assert liquid type
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 1;  // Assert flavour
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 1;  // Assert restart cycle
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Input\n" << endl;
  insig = 0;  // Assert flavour
  for (i=0;i<20;i++) {
    clock = 0; 
   sc_start(1,SC_NS);
    clock = 1; 
    sc_start(1,SC_NS);
  }

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0; // Terminate simulation

 }
