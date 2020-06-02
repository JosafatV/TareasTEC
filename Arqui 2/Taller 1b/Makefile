CC = gcc -Wall

SRC = main.c
OBJ = main.o
EXE = main

all: $(SRC)
		$(CC) -c $(SRC) -pthread
		$(CC) -o $(EXE) $(SRC) -pthread
	
run: $(EXE)
		./main

reset:
		rm main.o
		rm main
		clear
