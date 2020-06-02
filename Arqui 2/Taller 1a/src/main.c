#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "../include/linked_list.h"

typedef struct ThreadParams{
    Node_t* head;
    int time;
    int reps;
} params_t;

typedef struct ThreadParams2{
    Node_t* first;
    Node_t* second;
    Node_t* result;
    int reps;
} params2_t;



/**
 * Generates a random 8 bit number and waits for a
 * determined amount of time before returning the value
 * param int ms: amount of miliseconds to wait after creation
 * return: and 8 bit number stored in an int
 */
int timedGen (int ms) {
    int new = (rand() % 256);
    usleep(ms*1000); // change to mili
    return new;
}

/**
 * Fills a linked_list with data.
 * param void* tparams: a params_t* casted to be passed as argument in a thread
 * return: NULL, linked_list should be accesible by the passed parameter.
 */
void* maker (void* tparams){
    params_t* params = (params_t*) tparams;
    Node_t* array = params->head;
    int time = params->time;
    int reps = params->reps;

    for (int i = 0; i<reps; i++){
        int val = timedGen(time);
        //printf("Number generated in %dms is %d \n", time, val);
        push_back(&array, val);
    }
    /*
    // TESTING
    int len = get_length(array);
    printf("the length of the array %d ms is: %d \n", time, len);
    print_list(array);
    */
    return NULL;
}

/**
 * Fills a linked_list with the AND data of two other linked_lists.
 * Linked_lists should be of the same size
 * param void* tparams: a params_t2* casted to be passed as argument in a thread
 * return: NULL, linked_list should be accesible by the passed parameter.
 */
void* ander (void* tparams) {
    params2_t* params = (params2_t*) tparams;
    Node_t* head1 = params->first;
    Node_t* head2 = params->second;
    Node_t* head3 = params->result;
    int reps = params->reps;
    int a = 0, b = 0, c = 0;
	int i = 1;

    while (reps>=i) {
        // wait until next element exist on both linked_lists
		if (get_length(head1) > i) {
			if (get_length(head2) > i) {
				a = get_at(head1, i);
				b = get_at(head2, i);
				c = a & b;
        		push_back(&head3, c);
				i++;
    		}
		}
	}
    return NULL;
}

/**
 * This program creates 2 list of 8 bit numbers and outputs
 * a linked_list with the bitwise AND product of the matching
 * positions on the vectors.
 * [...,     x,     ...]
 * [...,     y,     ...]
 * [..., (x AND y), ...]
 */
int main() {
    pthread_t thread1, thread2, thread3;
	Node_t* head1 = NULL;
	Node_t* head2 = NULL;
	Node_t* head3 = NULL;
    int ret1 = 0, ret2 = 0, ret3 = 0;
    int repetitions = 100000;

    params_t* tenms;
    tenms = malloc(sizeof(params_t));
    tenms->head=head1;
    tenms->time=10;
    tenms->reps=repetitions;

    params_t* fivems;
    fivems = malloc(sizeof(params_t));
    fivems->head=head2;
    fivems->time=5;
    fivems->reps=repetitions;

    params2_t* andParams;
    andParams = malloc(sizeof(params2_t));
    andParams->result=head3;
    andParams->reps=repetitions;

    srand(time(0));

    // Initialize pointers addresses
    push_back(&tenms->head, 0);
    push_back(&fivems->head, 0);
    push_back(&andParams->result, 0);

    // Catch direction of pointers
    void* h1 = tenms->head;
    void* h2 = fivems->head;
    void* h3 = andParams->result;

	// Set known pointer directions
    andParams->first=h1;
    andParams->second=h2;

    // Create threads
    ret1 = pthread_create (&thread1, NULL, maker, (void*) tenms);
    if(ret1) {
        printf("Error creating thread 1: = %d\n", ret1);
    }
    
    ret2 = pthread_create (&thread2, NULL, maker, (void*) fivems);
    if(ret2) {
        printf("Error creating thread 2: = %d\n", ret2);
    }
    ret3 = pthread_create (&thread3, NULL, ander, (void*) andParams);
    if(ret3) {
        printf("Error creating thread 3: = %d\n", ret3);
    }
       
    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("the resulting lists are: \n");
    print_list(h1);
    print_list(h2);
    print_list(h3);

    return 0;
}
