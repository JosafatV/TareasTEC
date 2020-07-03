#include <stdio.h>
#include <stdlib.h>

int main () {
	int i, j;
	const int LIST_SIZE = 4;
	// change to RANDOM values
	const int X_val = 1;
    int *S = (int*)malloc(sizeof(int)*LIST_SIZE*LIST_SIZE);
    
    
    // Init the vectors 
        /*
    for(i = 0; i < LIST_SIZE; i++) {
		for (j = 0; j < LIST_SIZE; j++) {
			S[i][j] = 1;
			X[i][j] = i;
		}
    }*/
    
        // Display the result to the screen
    for(i = 0; i < LIST_SIZE; i++) {
		printf ("| ");
		for (j=0; j < LIST_SIZE; j++) {
			printf ("%d | ", 0);//S[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
