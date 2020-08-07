#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char completed = 'c';

typedef struct {
	char node;
	char status;
	short wait;
} call_t;


int main() {
	int n = 5;
	int i = 0;
	call_t generiCall = {'a', 'p', 15};
	call_t allCalls[n];
	for (i=0; i<n; i++) {
		allCalls[i] = generiCall;
	}
	
	allCalls[2].node = 'b';
	allCalls[2].status = completed;
	allCalls[2].wait = 25;
	
	for (i=0; i<n; i++) {
		printf("call %d node is: %c\n", i, allCalls[i].node);
		printf("call %d status is: %c\n", i, allCalls[i].status);
		printf("call %d wait is: %d\n", i, allCalls[i].wait);
	}
	
	printf ( "\n+++ CASTING TEST +++\n");
	
	printf("call3 %d node is: %c\n", i, allCalls[3].node);
	printf("call3 %d status is: %c\n", i, allCalls[3].status);
	printf("call3 %d wait is: %d\n", i, allCalls[3].wait);
	
	int* msg = (int*) &allCalls[3];
	printf("msg is %d\n", *msg);
	call_t* rcv = (call_t*) msg;
	
	printf("rcv %d node is: %c\n", i, rcv->node);
	printf("rcv %d status is: %c\n", i, rcv->status);
	printf("rcv %d wait is: %d\n", i, rcv->wait);
	
	return 0;
}
