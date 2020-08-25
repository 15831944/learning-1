CC = gcc
EXECUTABLES = dup manyterm manyterm_bad filedes_io
OTHER_FILES = junk.out

all: $(EXECUTABLES)

dup: dup.c
	$(CC) -o dup dup.c

manyterm_bad: manyterm.c
	$(CC) -o manyterm_bad manyterm.c -DBADCODE
	
manyterm: manyterm.c
	$(CC) -o manyterm manyterm.c

filedes_io: filedes_io.c
	$(CC) -o filedes_io filedes_io.c
				
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done