CC = gcc
AR = ar
RL = ranlib
NM = nm
LD = ld
EX = export

SRC = saxpy.c
EXE = saxpy

SRC_OMP = omp_saxpy.c
EXE_OMP = omp_saxpy

LINKEDLIST_LIB = lib_linked_list.a
LIBS = $(LIB_DIR)$(LINKEDLIST_LIB) 

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

all:
		make normal
		make parallel

normal:
		$(CC) -c $(SRC) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE) $(SRC) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o

parallel:
		$(CC) -c $(SRC_OMP) -fopenmp
		$(CC) -o $(BIN_DIR)$(EXE_OMP) $(SRC_OMP) $(LIBS) -I$(INCLUDE_DIR) -fopenmp
		rm *.o

clean:
		rm ../bin/$(EXE)
		rm ../bin/$(EXE_OMP)
		clear
