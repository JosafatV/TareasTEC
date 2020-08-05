CC = g++

IFLAG = -I/opt/systemc/include
LFLAG = -L/opt/systemc/lib-linux64
FLAGS = -lsystemc -lm

SRC_C = machine.cpp
EXE_C = machine

#export LD_LIBRARY_PATH=/opt/systemc/lib-linux64

machine:
		$(CC) $(IFLAG) $(LFLAG) -o $(EXE_C) $(SRC_C) $(FLAGS)
		./$(EXE_C)

run:
		./$(EXE_H)

		