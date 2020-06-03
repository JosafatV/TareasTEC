#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <emmintrin.h> 
#include <smmintrin.h>

int main () {

	/* Función para que el usuario ingrese valores va aquí */

	__m128i m0 = _mm_set_epi32 (77, 35, 13, 89);
	__m128i m1 = _mm_set_epi32 (50, 25, 31, 11);
	__m128i m2 = _mm_set_epi32 (29, 20, 15, 17);
	
	__m128i r0 = _mm_max_epi32 (m0, m1);
	__m128i r1 = _mm_max_epi32 (r0, m2);

	int data = 0;

	printf("+++ Vectores ingresados: +++\n \t");
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
