#CC = gcc
AR = ar rv
RL = ranlib
NM = nm -s
LD = ld -o

LIBNAME = libprand
LIBSRC = $(LIBNAME).c
LIBA = $(LIBNAME).a
LIBO = $(LIBNAME).o

all: $(SERVER_SRC) $(LIBSRC)
		make lib_prand
		make clean

lib_prand:
		$(CC) -c $(LIBSRC)
		$(AR) $(LIBA) $(LIBO)
		$(RL) $(LIBA)
		$(NM) $(LIBA)

clean:
		rm *.o
