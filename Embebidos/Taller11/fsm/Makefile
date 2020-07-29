CC = g++

IFLAG = -I/opt/systemc/include
LFLAG = -L/opt/systemc/lib-linux64
FLAGS = -lsystemc -lm

SRC_H = main.cpp
EXE_H = main

#export LD_LIBRARY_PATH=/opt/systemc/lib-linux64

machine:
		$(CC) $(IFLAG) $(LFLAG) -o $(EXE_H) $(SRC_H) $(FLAGS)
		./$(EXE_H)

run:
		./$(EXE_H)

		