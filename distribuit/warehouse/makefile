CC = gcc

all: warehouse

warehouse: warehouse.c
	$(CC) -fPIC -o warehouse warehouse.c

clean:
	if [ -f warehouse ]; then rm warehouse; fi;