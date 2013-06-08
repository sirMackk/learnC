CFLAGS=-Wall -g

clean:
	rm -f ex1

all:
	make ex1
	make ex2

clean_all:
	rm -f ex1
	rm -f ex2