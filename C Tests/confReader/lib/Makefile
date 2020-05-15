
LIB = libconfReader
LIBA = $(LIB).a
LIBO = $(LIB).o
LIBSRC = $(LIB).c


INC_DIR = ../include/
LIB_DIR=../lib/
CC = gcc -c -I$(INC_DIR)
AR = ar rvs
		

library:
		$(CC) $(LIBSRC)
		$(AR) $(LIB) $(LIBO)

clean:
		rm *.o
