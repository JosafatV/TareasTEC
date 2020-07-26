CC = g++

IFLAG = -I/opt/systemc/include
LFLAG = -L/opt/systemc/lib-linux64
FLAGS = -lsystemc -lm

SRC_X = main_exor.cpp
EXE_X = main_exor

SRC_A = main_and.cpp
EXE_A = main_and

#export LD_LIBRARY_PATH=/opt/systemc/lib-linux64

exor:
		$(CC) $(IFLAG) $(LFLAG) -o $(EXE_X) $(SRC_X) $(FLAGS)
		./$(EXE_X)

and:
		$(CC) $(IFLAG) $(LFLAG) -o $(EXE_A) $(SRC_A) $(FLAGS)
		./$(EXE_X)