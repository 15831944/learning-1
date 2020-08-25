CC = gcc
AR = ar
EXECUTABLES = noecho rawmode getcaps new_getcaps
OBJECTS =  
OTHER_FILES = 

all: $(EXECUTABLES)

noecho: noecho.c
	$(CC) -o noecho noecho.c

rawmode:rawmode.c
	$(CC) -o rawmode rawmode.c

getcaps:getcaps.c
	$(CC) -o getcaps getcaps.c -lcurses
	
new_getcaps:new_getcaps.c
	$(CC) -o new_getcaps new_getcaps.c -lcurses
			
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
	