CC = gcc

BIN_DIR = ../bin/
LIB_DIR = ../lib/
INC_DIR = ../include/

SRC_COMP = compare.c
EXE_COMP = compare

SRC_SIMD = vxm.c
EXE_SIMD = vxm

all:
		#make compare
		make vxm

compare:
		$(CC) -o $(BIN_DIR)$(EXE_COMP) $(SRC_COMP) -msse4
		$(BIN_DIR)$(EXE_COMP)
		
vxm:
		$(CC) -o $(BIN_DIR)$(EXE_SIMD) $(SRC_SIMD) -msse4
		clear
		$(BIN_DIR)$(EXE_SIMD)


