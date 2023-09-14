PHONY += all
all:
	gcc -o write1 write1.c
	gcc -o write2 write2.c
	gcc -o write3 write3.c
	gcc -o lseek lseek.c

PHONY += clean
clean:
	rm -rf write1 write2 write3 lseek

.PHONE: $(PHONY)