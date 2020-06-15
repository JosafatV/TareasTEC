CC = gcc
AR = ar
RL = ranlib
NM = nm
LD = ld
EX = export

SRC_S = saxpy.c
EXE_S = saxpy

SRC_SOMP = omp_saxpy_sse.c
EXE_SOMP = omp_saxpy

SRC_E = euler.c
EXE_E = euler

SRC_EOMP = euler_omp.c
EXE_EOMP = euler_omp

SRC_H = harmonic.c
EXE_H = harmonic

SRC_HOMP = harmonic_omp.c
EXE_HOMP = harmonic_omp

FLAGS = -fopenmp 

LINKEDLIST_LIB = lib_linked_list.a
LIBS = $(LIB_DIR)$(LINKEDLIST_LIB) 

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

all:
		make saxpy
		make omp_saxpy
		make euler
		make omp_euler
		make harmonic
		make omp_harmonic

saxpy:
		$(CC) -o $(BIN_DIR)$(EXE_S) $(FLAGS) $(SRC_S) $(LIBS) -I$(INCLUDE_DIR) 

omp_saxpy:
		$(CC) -o $(BIN_DIR)$(EXE_SOMP) $(FLAGS) $(SRC_SOMP) $(LIBS) -I$(INCLUDE_DIR) 
		
euler:
		$(CC) -o $(BIN_DIR)$(EXE_E) $(FLAGS) $(SRC_E) $(LIBS) -I$(INCLUDE_DIR) 
		
omp_euler:
		$(CC) -o $(BIN_DIR)$(EXE_EOMP) $(FLAGS) $(SRC_EOMP) $(LIBS) -I$(INCLUDE_DIR) 
		
harmonic:
		$(CC) -o $(BIN_DIR)$(EXE_H) $(FLAGS) $(SRC_H) $(LIBS) -I$(INCLUDE_DIR) -lm 

omp_harmonic:
		$(CC) -o $(BIN_DIR)$(EXE_HOMP) $(FLAGS) $(SRC_HOMP) $(LIBS) -I$(INCLUDE_DIR) -lm 
