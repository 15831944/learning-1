CC = gcc
AR = ar
EXECUTABLES = error 
OBJECTS = 
OTHER_FILES = 
LIBS =

all: $(EXECUTABLES)

error: error.c ../common/err.o
	$(CC) -fpic -o error  error.c ../common/err.o 

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
	