CC = gcc
AR = ar
EXECUTABLES = execlp execvp envprint execle appinit printIds callSystem callSystem1
OBJECTS = execs.o sys.o
OTHER_FILES = 

all: $(OBJECTS) $(EXECUTABLES)

execs.o:execs.c execs.h
	$(CC) -c execs.c -o execs.o

execlp:execlp.c ../common/err.o
	$(CC) -fPIC -o execlp execlp.c ../common/err.o

execvp:execvp.c ../common/err.o
	$(CC) -fPIC -o execvp execvp.c ../common/err.o

envprint:envprint.c
	$(CC) -fPIC -o envprint envprint.c
	
execle:execle.c ../common/err.o
	$(CC) -fPIC -o execle execle.c ../common/err.o

appinit:appinit.c execs.o
	$(CC) -fPIC -o appinit appinit.c execs.o

printIds:printIds.c
	$(CC) -fPIC -o printIds printIds.c

sys.o:sys.c
	$(CC) -fPIC -c sys.c -o sys.o

callSystem:callSystem.c ../common/err.o sys.o ../common/print_exit.o
	$(CC) -fPIC -o callSystem callSystem.c ../common/err.o sys.o ../common/print_exit.o
	
callSystem1:callSystem1.c ../common/err.o ../common/print_exit.o
	$(CC) -fPIC -o callSystem1 callSystem1.c ../common/err.o ../common/print_exit.o
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
	