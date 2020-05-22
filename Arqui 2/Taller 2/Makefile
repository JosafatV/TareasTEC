SRC_DIR = src/
LIB_DIR = lib/

CC = gcc -o
FLAGS = -fopenmp

LOEXE = bin/euler
LOSRC = euler_omp.c

all: 
		mkdir -p bin && make -C $(LIB_DIR) && make -C $(SRC_DIR)

run:
		./bin/omp_saxpy

slow:
		./bin/saxpy

euler:
		$(CC) $(LOEXE) $(FLAGS) $(LOSRC)
		./bin/euler

reset:
		rm -r bin/
		rm lib/*.a
		clear
