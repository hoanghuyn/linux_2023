PROJECT := main_prj

CUR_DIR := .

BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
LIB_DIR := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src

LIB_STATIC := $(LIB_DIR)/static
LIB_SHARED := $(LIB_DIR)/shared

INC_FLAGS := -I $(INC_DIR)

CC := gcc

PHONY += objs
objs:
	$(CC) -c $(INC_FLAGS) -o $(OBJ_DIR)/hello_hoang.o $(SRC_DIR)/hello_hoang.c
	$(CC) -c $(INC_FLAGS) -o $(OBJ_DIR)/hello_world.o $(SRC_DIR)/hello_world.c
	$(CC) -c $(INC_FLAGS) -o $(OBJ_DIR)/main.o main.c

PHONY += libstatic
libstatic: objs
	ar rcs $(LIB_STATIC)/lib$(PROJECT).a $(OBJ_DIR)/hello_hoang.o $(OBJ_DIR)/hello_world.o

PHONY += all
all: libstatic
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_STATIC) -l$(PROJECT)  -o $(BIN_DIR)/$(PROJECT)

PHONY += clean
clean:
	rm -rf $(OBJ_DIR)/*.o	\
	$(LIB_STATIC)/*.a	\
	$(BIN_DIR)/$(PROJECT) \

PHONY += run
run:
	$(BIN_DIR)/$(PROJECT)

PHONY += rebuild
rebuild: clean all

.PHONY: $(PHONY)