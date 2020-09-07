CC = gcc
AR = ar
EXECUTABLES = first_pipe readfile_pipe cmd_pipe pipe_sync popen_ex1 popen_ex2 fsort coprocess masteradd
OBJECTS = sync.o popen.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

first_pipe:first_pipe.c ../../common/err.o
	$(CC) -fPIC -o first_pipe first_pipe.c ../../common/err.o

readfile_pipe:readfile_pipe.c ../../common/err.o
	$(CC) -fPIC -o readfile_pipe readfile_pipe.c ../../common/err.o

cmd_pipe:cmd_pipe.c ../../common/err.o
	$(CC) -fPIC -o cmd_pipe cmd_pipe.c ../../common/err.o

sync.o:sync.c sync.h
	$(CC) -o sync.o -c sync.c

pipe_sync:pipe_sync.c ../../common/err.o sync.o
	$(CC) -fPIC -o pipe_sync pipe_sync.c ../../common/err.o sync.o
	
popen_ex1:popen_ex1.c ../../common/err.o
	$(CC) -fPIC -o popen_ex1 popen_ex1.c ../../common/err.o

popen.o:popen.c
	$(CC) -o popen.o -c popen.c
	
popen_ex2:popen_ex1.c ../../common/err.o popen.o
	$(CC) -fPIC -o popen_ex2 popen_ex1.c ../../common/err.o popen.o

fsort:fsort.c ../../common/err.o
	$(CC) -fPIC -o fsort fsort.c ../../common/err.o

coprocess:coprocess.c ../../common/err.o
	$(CC) -fPIC -o coprocess coprocess.c ../../common/err.o

masteradd:masteradd.c ../../common/err.o
	$(CC) -fPIC -o masteradd masteradd.c ../../common/err.o
	
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
	