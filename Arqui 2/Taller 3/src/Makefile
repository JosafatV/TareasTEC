CC = gcc

BIN_DIR = ../bin/
LIB_DIR = ../lib/
INC_DIR = ../include/

SRC_COMP = compare.c
EXE_COMP = compare

SRC_SIMD = vxm.c
EXE_SIMD = vxm

all:
		$(CC) -o $(BIN_DIR)$(EXE_COMP) $(SRC_COMP) -msse4
		$(CC) -o $(BIN_DIR)$(EXE_SIMD) $(SRC_SIMD) -msse4


