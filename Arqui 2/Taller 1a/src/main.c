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
} params2_t;

int timedGen (int ms) {
    int new = (rand() % 256);
    usleep(ms*1000); // change to mili
    return new;
}

void* maker (void* tparams){
    params_t* params = (params_t*) tparams;
    Node_t* array = params->head;
    int time = params->time;
    int reps = params->reps;

    for (int i = 0; i<reps; i++){
        int val = timedGen(time);
        //printf("Number generated is %d \n", val);
        push_back(&array, val);
    }

    return NULL;
}

void* ander (void* tparams) {
    params2_t* params = (params2_t*) tparams;
    Node_t* head1 = params->first;
    Node_t* head2 = params->second;
    Node_t* head3 = params->result;
    int reps = get_length(head1);
    int a = 0, b = 0, c = 0;

    for (int i = 0; i<reps; i++){
        a = get_at(head1, i);
        b = get_at(head2, i);
        c = a & b;
        push_back(&head3, c);
    }

    return NULL;
}

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

    srand(time(0));

    // Initialize pointer to get its address
    push_back(&tenms->head, 0);
    push_back(&fivems->head, 0);
    push_back(&andParams->result, 0);
    // Catch direction of pointers
    void* h1 = tenms->head;
    void* h2 = fivems->head;
    void* h3 = andParams->result;

    // Set known pointer directins
    andParams->first=h1;
    andParams->second=h2;
   
    // fill vectors
    maker((void*) tenms);
    maker((void*) fivems);
    ander(andParams);

    int bb = get_at(h2, 3);
    printf("The resulting lists are:\n");
	print_list(h1);
	print_list(h2);
    print_list(h3);

    return 0;
}
