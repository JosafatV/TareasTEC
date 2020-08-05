//file: helloworld.cpp
//All systemc modules should include systemc.h header file 

#include "systemc.h"

//Hello_world is a module name
SC_MODULE(hello_world) {
	SC_CTOR (hello_world) {
		//Nothing in constructor
	}
	// c++ like method
	void be_nice() {
		// Print to the console
		cout << "Hello World from systemc. \n";
	}
};

//sc_main in top level function like in c++ main
int sc_main(int argc, char* argv[]) {
	// hello world "object"
	hello_world hello("NULL");
	// print
	hello.be_nice();
	return(0);
}


