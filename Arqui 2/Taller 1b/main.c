#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int global = 0;
pthread_mutex_t lock;

void* increment () {
	// This lock protects the critical area that is the global variable
	printf ("locking...\n");	
	pthread_mutex_lock(&lock);
	
	printf ("starting counter...\n");
	for (int i = 0; i<1000000000; i++){
		global++;
	}
	
	pthread_mutex_unlock(&lock);
	printf ("unlocking...\n");
	return NULL;
}

int main() {
	pthread_t thread1, thread2;
	int ret1 = 0, ret2 = 0;
	
    // Create threads
    ret1 = pthread_create (&thread1, NULL, increment, NULL);
    if (ret1) {
		printf("pthread1 error: %d \n", ret1);
	}
	
	ret2 = pthread_create (&thread2, NULL, increment, NULL);
	if (ret2) {
		printf("pthread2 error: %d \n", ret2);
	}
	
    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Global variable is: %d \n", global);

    return 0;
}
