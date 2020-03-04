CC = gcc
AR = ar
RL = ranlib
NM = nm
LD = ld
EX = export

SRC = main.c
EXE = main

LINKEDLIST_LIB = lib_linked_list.a
LIBS = $(LIB_DIR)$(LINKEDLIST_LIB) 

LIB_DIR = ../lib/
INCLUDE_DIR = ../include/
BIN_DIR = ../bin/

main:
	$(CC) -c $(SRC) -pthread
	$(CC) -o $(BIN_DIR)$(EXE) $(SRC) $(LIBS) -I$(INCLUDE_DIR) -pthread

reset:
	rm ../bin/main
	rm main.o
	clear
