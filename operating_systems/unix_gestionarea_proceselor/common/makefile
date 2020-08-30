CC = gcc
AR = ar
EXECUTABLES = 
OBJECTS = err.o print_exit.o
OTHER_FILES = 

all: $(OBJECTS)

err.o: err.c hdr.h
	$(CC) -c err.c

print_exit.o:print_exit.c print_exit.h
	$(CC) -c print_exit.c
	
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	