PROJECT := dynamic_loading
CUR_DIR := $(realpath .)
CC := gcc

PHONY += all
all:
	$(CC) -o $(PROJECT) $(CUR_DIR)/dynamicLoading.c -ldl

run:
	@./$(PROJECT)

clean:
	rm -rf $(PROJECT)