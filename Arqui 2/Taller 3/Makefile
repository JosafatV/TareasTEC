SRC_DIR = src/
LIB_DIR = lib/
BIN_DIR = bin/

EXE_COMP = compare
EXE_SIMD = vxm

all: 
		mkdir -p bin && make -C $(SRC_DIR)

compare:
		$(BIN_DIR)$(EXE_COMP)

vxm:
		$(BIN_DIR)$(EXE_SIMD)

reset:
		rm -r bin/
		clear
