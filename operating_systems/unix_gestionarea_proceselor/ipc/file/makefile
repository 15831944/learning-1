CC = gcc
AR = ar
EXECUTABLES = master1 child1 master2 child21 child22
OBJECTS = 
OTHER_FILES = FIS_INTERF

all: $(EXECUTABLES) $(OBJECTS)

master1:master1.c interfata.h ../../common/err.o
	$(CC) -fPIC -o master1 master1.c ../../common/err.o
	
child1:child1.c interfata.h ../../common/err.o
	$(CC) -fPIC -o child1 child1.c ../../common/err.o

master2:master2.c interfata.h ../../common/err.o
	$(CC) -fPIC -o master2 master2.c ../../common/err.o
	
child21:child21.c interfata.h ../../common/err.o
	$(CC) -fPIC -o child21 child21.c ../../common/err.o

child22:child22.c interfata.h ../../common/err.o
	$(CC) -fPIC -o child22 child22.c ../../common/err.o
		
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
	