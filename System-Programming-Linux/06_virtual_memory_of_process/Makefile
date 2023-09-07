PHONY += all
all:
	gcc -o cli1 cli1.c
	gcc -o cli2 cli2.c
	gcc -o env1 env1.c
	gcc -o env2 env2.c
	gcc -o env3 env3.c

PHONY += clean
clean:
	rm -rf cli1 cli2 env1 env2 env3

.PHONE: $(PHONY)