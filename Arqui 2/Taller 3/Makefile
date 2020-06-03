SRC_DIR = src/
LIB_DIR = lib/
BIN_DIR = bin/

EXE_COMP = compare
EXE_SIMD = vxm

all: 
		mkdir -p bin && make -C $(LIB_DIR) && make -C $(SRC_DIR)

run:
		$(BIN_DIR)$(EXE_COMP)
		$(BIN_DIR)$(EXE_SIMD)

reset:
		rm -r bin/
		rm lib/*.a
		clear
