CC = gcc
EXECUTABLES = onexit pthread_cleanup child_demo1 child_demo2 child_demo3
OBJECTS = child.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

onexit: onexit.c
	$(CC) -o onexit onexit.c

pthread_cleanup: pthread_cleanup.c
	$(CC) -o pthread_cleanup pthread_cleanup.c -lpthread

child.o: child.c child.h
	$(CC) -c child.c

child_demo1: child_demo1.c child.o
	$(CC) -o child_demo1 child_demo1.c child.c
	
child_demo2: child_demo2.c child.o
	$(CC) -o child_demo2 child_demo2.c child.c

child_demo3: child_demo3.c child.o
	$(CC) -o child_demo3 child_demo3.c child.c
			
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done