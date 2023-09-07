CC := gcc

PHONY += all
all:
	$(CC) -o alarm main.c

PHONY += clean
clean:
	rm -rf alarm

PHONY += run
run:
	./alarm

.PHONY: $(PHONY)