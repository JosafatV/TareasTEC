#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <emmintrin.h> 
#include <smmintrin.h>

int main () {

	__m128i vector = _mm_set_epi32 (11, 29, 69, 72);
	
	// Row 0				Col:	0	  1     2     3
	__m128i m0a = _mm_set_epi32 (0, 1, 0, 1);
				__m128i m0b = _mm_set_epi32 (0, 2, 0, 1);
	// Row 1						|     |     |     |
	__m128i m1a = _mm_set_epi32 (0, 1, 0, 1);
				__m128i m1b = _mm_set_epi32 (0, 1, 0, 2);
	// Row 2						|     |     |     |
	__m128i m2a = _mm_set_epi32 (0, 1, 0, 1);
				__m128i m2b = _mm_set_epi32 (0, 2, 0, 1);
	// Row 3						|     |     |     |
	__m128i m3a = _mm_set_epi32 (0, 1, 0, 1);
				__m128i m3b = _mm_set_epi32 (0, 1, 0, 2);

	// _mm_mul multpiplies the lower 32 bits of m and stores them in 64 bits of r
	__m128i r0a, r0b, r1a, r1b, r2a, r2b, r3a, r3b;
	r0a = _mm_mul_epi32(m0a, vector);
	r0b = _mm_mul_epi32(m0b, vector);
	r1a = _mm_mul_epi32(m1a, vector);
	r1b = _mm_mul_epi32(m1b, vector);

	r2a = _mm_mul_epi32(m2a, vector);
	r2b = _mm_mul_epi32(m2b, vector);
	r3a = _mm_mul_epi32(m3a, vector);
	r3b = _mm_mul_epi32(m3b, vector);

	int data = 0;

	printf("+++ Matriz resultante: +++\n \t");
	data = _mm_extract_epi32(r0a, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0a, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0b, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0b, 0); 	printf("%d \t", data);
	printf("\n \t");
	data = _mm_extract_epi32(r1a, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1a, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1b, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1b, 0); 	printf("%d \t", data);
	printf("\n \t");
	data = _mm_extract_epi32(r2a, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2a, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2b, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2b, 0); 	printf("%d \t", data);
	printf("\n \t");
	data = _mm_extract_epi32(r3a, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r3a, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r3b, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r3b, 0); 	printf("%d \t", data);
	printf("\n");

	return 0;
}
