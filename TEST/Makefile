
var := "0"

var1 = $(var)
var2 := $(var)
var3 ?= $(var)

var := "1"

rule3:
	@echo "var1: $(var1)"
	@echo "var2: $(var2)"
	@echo "var3: $(var3)"

rule1:
	@echo "I'm rule 1"

rule2:
	@echo "I'm rule 2"

all: main.c
	gcc -o hello main.c

clean: hello
	rm -rf hello