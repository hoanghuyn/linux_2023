PHONY += all
all:
	gcc -o orphan orphan.c
	gcc -o zombie1 zombie1.c
	gcc -o zombie2 zombie2.c

PHONY += clean
clean:
	rm -rf orphan zombie1 zombie2

.PHONY: $(PHONY)