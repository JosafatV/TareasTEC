SRC_DIR = src/
LIB_DIR = lib/

CC = gcc -o
FLAGS = -fopenmp

all: 
		mkdir -p bin && make -C $(LIB_DIR) && make -C $(SRC_DIR)

saxpy_omp:
		./bin/omp_saxpy

saxpy:
		./bin/saxpy

euler:
		./bin/euler

euler_omp:
		./bin/euler_omp
		
harmonic:
		./bin/harmonic

harmonic_omp:
		./bin/harmonic_omp
		
reset:
		rm -r bin/
		rm lib/*.a
		clear
