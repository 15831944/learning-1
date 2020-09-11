CC = gcc
AR = ar
EXECUTABLES = mkdump
OBJECTS = 
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

mkdump:mkdump.c
	$(CC) -fPIC -o mkdump mkdump.c -lnsl
			
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
	