CC = gcc
AR = ar
EXECUTABLES = overflow canary saferio
OBJECTS =  
OTHER_FILES = 

all: $(EXECUTABLES)

overflow:overflow.c
	$(CC) -o overflow overflow.c
canary:canary.c
	$(CC) -o canary canary.c

saferio:saferio.c
	$(CC) -o saferio saferio.c
			
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
	