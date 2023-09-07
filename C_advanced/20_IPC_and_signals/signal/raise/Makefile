CC := gcc

PHONY += all
all:
	$(CC) -o raise_signal raise_signal.c

PHONY += clean
clean:
	rm -rf raise_signal

PHONY += run
run:
	./raise_signal

.PHONY: $(PHONY)