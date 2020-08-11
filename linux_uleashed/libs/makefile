CC = gcc
AR = ar
EXECUTABLES = liberr.a errtest liberr.so errtests dlerrtest
OBJECTS = liberr.o 
OTHER_FILES = errtest.log

all: $(EXECUTABLES)

liberr.o:liberr.c liberr.h
	$(CC) -H -fPIC -c liberr.c -o liberr.o

liberr.a: liberr.o
	$(AR) rcs liberr.a liberr.o
errtest:errtest.c liberr.a
	$(CC) -g -o errtest errtest.c -L. -lerr
liberr.so:liberr.o
	$(CC) -g -shared -o liberr.so liberr.o -lc
errtests: liberr.so errtest.c
	$(CC) -g errtest.c -o errtests -L. -lerr
dlerrtest: dlerrtest.c liberr.so
	$(CC) dlerrtest.c -o dlerrtest -g -ldl
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
	