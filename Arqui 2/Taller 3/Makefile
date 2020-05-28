SRC_DIR = src/
LIB_DIR = lib/
EXE_DIR = bin/

all: 
		mkdir -p bin && make -C $(LIB_DIR) && make -C $(SRC_DIR)

reset:
		rm -r bin/
		rm lib/*.a
		clear
