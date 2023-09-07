PROJECT := string_utils
SHARED_LIB_NAME := lib$(PROJECT).so

CUR_DIR := $(realpath .)

BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
LIB_DIR := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src

LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

INC_FLAGS := -I $(INC_DIR)

BUILD_SHARED_LIB_FLAGS := -g -fPIC -shared

CC := gcc

PHONY += objs
objs:
	$(CC) -c $(INC_FLAGS) -o $(OBJ_DIR)/string_functions.o $(SRC_DIR)/string_functions.c
	$(CC) -c $(INC_FLAGS) -o $(OBJ_DIR)/main.o main.c

PHONY += libstatic
libstatic: objs
	ar rcs $(LIB_STATIC_DIR)/lib$(PROJECT).a $(OBJ_DIR)/string_functions.o

PHONY += libshared
libshared:
	@$(CC) $(INC_FLAGS) $(BUILD_SHARED_LIB_FLAGS) $(SRC_DIR)/string_functions.c -o $(LIB_SHARED_DIR)/lib$(PROJECT).so

PHONY += install
install: libshared
	@install $(LIB_SHARED_DIR)/$(SHARED_LIB_NAME) /usr/lib

PHONY += link_lib_static
link_lib_static: libstatic
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_STATIC_DIR) -l$(PROJECT) -o $(BIN_DIR)/$(PROJECT)

PHONY += link_lib_shared
link_lib_shared: install
	@$(CC) -c $(INC_FLAGS) $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o
	@$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(PROJECT) -o $(BIN_DIR)/$(PROJECT)

PHONY += clean
clean:
	rm -rf $(OBJ_DIR)/*.o	\
	$(LIB_STATIC_DIR)/*.a	\
	$(LIB_SHARED_DIR)/*.so	\
	$(BIN_DIR)/*			\
	/usr/lib/$(SHARED_LIB_NAME)

PHONY += run
run:
	$(BIN_DIR)/$(PROJECT)

PHONY += rebuild
rebuild: clean all

.PHONY: $(PHONY)