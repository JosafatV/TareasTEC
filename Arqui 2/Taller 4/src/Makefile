CC = gcc
AR = ar
RL = ranlib
NM = nm
LD = ld
EX = export

SRC_S = saxpy.c
EXE_S = saxpy

SRC_SOMP = omp_saxpy.c
EXE_SOMP = omp_saxpy

SRC_E = euler.c
EXE_E = euler

SRC_EOMP = euler_omp.c
EXE_EOMP = euler_omp

SRC_H = harmonic.c
EXE_H = harmonic

LINKEDLIST_LIB = lib_linked_list.a
LIBS = $(LIB_DIR)$(LINKEDLIST_LIB) 

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

all:
		make harmonic

saxpy:
		$(CC) -c $(SRC_S) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_S) $(SRC_S) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o

omp_saxpy:
		$(CC) -c $(SRC_SOMP) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_SOMP) $(SRC_SOMP) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o
		
euler:
		$(CC) -c $(SRC_E) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_E) $(SRC_E) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o
		
omp_euler:
		$(CC) -c $(SRC_EOMP) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_EOMP) $(SRC_EOMP) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o	
		
harmonic:
		$(CC) -c $(SRC_H) -fopenmp -lm
		$(CC) -o $(BIN_DIR)$(EXE_H) $(SRC_H) $(LIBS) -I$(INCLUDE_DIR) -fopenmp -lm
		rm *.o

clean:
		rm ../bin/$(EXE)
		rm ../bin/$(EXE_OMP)
		clear
