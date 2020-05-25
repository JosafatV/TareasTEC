CC = gcc

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

LINKEDLIST_LIB = lib_linked_list.a
LIBS = $(LIB_DIR)$(LINKEDLIST_LIB)

SRC = saxpy.c
EXE = saxpy

SRC_OMP = omp_saxpy.c
EXE_OMP = omp_saxpy

SRC_SIMD = simd_saxpy.c
EXE_SIMD = simd_saxpy 

all:
		make normal
		make parallel
		make simd

normal:
		$(CC) -c $(SRC) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE) $(SRC) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o

parallel:
		$(CC) -c $(SRC_OMP) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_OMP) $(SRC_OMP) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o
		
simd:
		$(CC) -c $(SRC_SIMD)
		$(CC) -o $(BIN_DIR)$(EXE_SIMD) $(SRC_SIMD) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o

clean:
		rm ../$(BIN_DIR)$(EXE)
		rm ../$(BIN_DIR)$(EXE_OMP)
		rm ../$(BIN_DIR)$(EXE_SIMD)
		clear
