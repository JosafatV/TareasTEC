SRC_DIR = src/
LIB_DIR = lib/
EXE_DIR = bin/

all: 
		mkdir -p bin && make -C $(LIB_DIR) && make -C $(SRC_DIR)
		
nor:
		./$(EXE_DIR)saxpy
		
omp:
		./$(EXE_DIR)omp_saxpy
		
simd:
		./$(EXE_DIR)simd_saxpy	
		
hello:
		gcc -o /bin/hello helloWorld.c -msse4
		
check:
		grep flags /proc/cpuinfo


reset:
		rm -r bin/
		rm lib/*.a
		clear
