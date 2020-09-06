CC = gcc
AR = ar
EXECUTABLES = execmaster1 execchild1 execmaster2 execchild2
OBJECTS = 
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

execmaster1:execmaster1.c
	$(CC) -fPIC -o execmaster1 execmaster1.c

execchild1: execchild1.c
	$(CC) -fPIC -o execchild1 execchild1.c

execmaster2:execmaster2.c
	$(CC) -fPIC -o execmaster2 execmaster2.c

execchild2: execchild2.c
	$(CC) -fPIC -o execchild2 execchild2.c
		
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
	