CC = gcc
AR = ar
RL = ranlib
NM = nm
LD = ld
EX = export

SRC = main.c
EXE = main

LIB = libconfReader.a
LIBS = $(LIB_DIR)$(LIB) 

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

main:
		$(CC) -c $(SRC)
		$(CC) -o $(BIN_DIR)$(EXE) $(SRC) $(LIBS) -I$(INCLUDE_DIR)

clean:
		rm ../bin/main
		rm main.o
		clear
