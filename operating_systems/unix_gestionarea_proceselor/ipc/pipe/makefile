CC = gcc
AR = ar
EXECUTABLES = first_pipe
OBJECTS = 
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

first_pipe:first_pipe.c ../../common/err.o
	$(CC) -fPIC -o first_pipe first_pipe.c ../../common/err.o
		
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
	