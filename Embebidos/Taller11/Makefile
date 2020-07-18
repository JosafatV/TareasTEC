CC = g++

IFLAG = -I/opt/systemc/include
LFLAG = -L/opt/systemc/lib-linux64
FLAGS = -lsystemc -lm

SRC_H = helloworld.cpp
EXE_H = hello_systemc

#export LD_LIBRARY_PATH=/opt/systemc/lib-linux64

hello:
		$(CC) $(IFLAG) $(LFLAG) -o $(EXE_H) $(SRC_H) $(FLAGS)
		./$(EXE_H)


run:
		./$(EXE_H)

		