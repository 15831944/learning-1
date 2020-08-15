CC = gcc
AR = ar
EXECUTABLES = debugme callstk
OBJECTS =  
OTHER_FILES = core 

all: $(EXECUTABLES)

debugme:debugme.c
	$(CC) -ggdb -o debugme debugme.c
callstk:callstk.c
	$(CC) -ggdb -o callstk callstk.c
				
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
	