CC = gcc
EXECUTABLES = mem mmcat badmem
OTHER_FILES = 

all: $(EXECUTABLES)

mem: mem.c
	$(CC) -o mem mem.c
mmcat:mmcat.c
	$(CC) -o mmcat mmcat.c
	
badmem: badmem.c
	$(CC) -ggdb -o badmem badmem.c -lefence
				
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done