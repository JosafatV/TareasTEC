#CC = gcc
SRC = main.c
OUT = ../bin/RPTimer

LIBPRAND = ../lib/libprand.a

CFLAGS = -I../include
LDFLAGS = -L../lib 

main: $(SRC)
		$(CC) -o $(OUT) $(SRC) $(CFLAGS) $(LDFLAGS) $(LIBPRAND) -pthread

clean:
		rm main.o
		clear
