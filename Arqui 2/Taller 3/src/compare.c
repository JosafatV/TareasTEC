#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <emmintrin.h> 
#include <smmintrin.h>

/**
 * \param val the value to be printed  
 * \param x the column, if y is 1. Entering 4 will print no number!
 * \param y if y is 0 is an edge
 */
void print_matrix (int val, int x, int y) {

	if (y) {
		switch (x) {
			case 0:
				printf ("| %d \t\t", val);
				break;
			case 1:
				printf ("| %d \t\t", val);
				break;
			case 2:
				printf ("| %d \t\t", val);
				break;
			case 3:
				printf ("| %d \t\t|\n", val);
				break;
			default:
				break;
		}
	} else {
		printf ("_________________________________________________________________\n");
	}
}

int main () {
	
	__m128i m0, m1, m2;
	int v0, v1, v2, v3;

	printf("Enter the values for the matrix:\n");	
	for (int i=0; i<3; i++){
		//printf( "Enter row %d \n", i);
		scanf("%d", &v0);
		scanf("%d", &v1);
		scanf("%d", &v2);
		scanf("%d", &v3);
/*
		print_matrix(55, 1, 0);
		print_matrix(v0, 0, 1);
		print_matrix(v1, 1, 1);
		print_matrix(v2, 2, 1);
		print_matrix(v3, 3, 1);
		print_matrix(55, 1, 0);
*/
		switch (i){
		case 0:
			m0 = _mm_set_epi32 (v0, v1, v2, v3);			
			break;
		case 1:
			m1 = _mm_set_epi32 (v0, v1, v2, v3);			
			break;
		case 2:
			m2 = _mm_set_epi32 (v0, v1, v2, v3);			
			break;
		default:
			break;
		}
	}

	__m128i r0 = _mm_max_epi32 (m0, m1);
	__m128i r1 = _mm_max_epi32 (r0, m2);

	int data = 0;

	printf("+++ Matriz ingresada: +++\n \t");
	data = _mm_extract_epi32(m0, 3); 	printf("%d \t", data);
	data = _mm_extract_epi32(m0, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(m0, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(m0, 0); 	printf("%d \t", data);
	printf("\n \t");
	data = _mm_extract_epi32(m1, 3); 	printf("%d \t", data);
	data = _mm_extract_epi32(m1, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(m1, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(m1, 0); 	printf("%d \t", data);
	printf("\n \t");
	data = _mm_extract_epi32(m2, 3); 	printf("%d \t", data);
	data = _mm_extract_epi32(m2, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(m2, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(m2, 0); 	printf("%d \t", data);
	printf("\n \n");
	printf("+++ Vector resultante: +++\n \t");
	data = _mm_extract_epi32(r1, 3); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 0); 	printf("%d \t", data);
	printf("\n\n");

	return 0;
}
