#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <emmintrin.h> 
#include <smmintrin.h>

int main () {

	__m128i vector = _mm_set_epi32 (10, 22, 1, 69);
	
	__m128i m0 = _mm_set_epi32 (1, 0, 0, 0);
	__m128i m1 = _mm_set_epi32 (2, 1, 0, 1);
	__m128i m2 = _mm_set_epi32 (3, 2, 1, 0);
	__m128i m3 = _mm_set_epi32 (4, 3, 2, 1);
	
	__m128i r0 = _mm_mul_epi32(vector, m0);
	__m128i r1 = _mm_mul_epi32(vector, m1);
	__m128i r2 = _mm_mul_epi32(vector, m2);
	__m128i r3 = _mm_mul_epi32(vector, m3);

	int data = 0;

	data = _mm_extract_epi32(r0, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r0, 3); 	printf("%d \t", data);
	printf("\n");
	data = _mm_extract_epi32(r1, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r1, 3); 	printf("%d \t", data);
	printf("\n");
	data = _mm_extract_epi32(r2, 0); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2, 1); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2, 2); 	printf("%d \t", data);
	data = _mm_extract_epi32(r2, 3); 	printf("%d \t", data);
	printf("\n");
	data = _mm_extract_epi32(r3, 0); 	printf("%d \t\t", data);
	data = _mm_extract_epi32(r3, 1); 	printf("%d \t\t", data);
	data = _mm_extract_epi32(r3, 2); 	printf("%d \t\t", data);
	data = _mm_extract_epi32(r3, 3); 	printf("%d \t\t", data);
	printf("\n");



	return 0;
}