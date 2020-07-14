CC = gcc

EXECUTABLES = constatare interventie supraveghere
OBJECTS = watchaccess.o

all: $(OBJECTS) $(EXECUTABLES)

watchaccess.o: watchaccess.c watchaccess.h
	$(CC) -fPIC -c watchaccess.c
constatare: constatare.c watchaccess.h watchaccess.o
	$(CC) -fPIC -o constatare constatare.c watchaccess.o
interventie: interventie.c watchaccess.h watchaccess.o
	$(CC) -fPIC -o interventie interventie.c watchaccess.o
supraveghere: supraveghere.c watchaccess.h watchaccess.o
	$(CC) -fPIC -o supraveghere supraveghere.c watchaccess.o
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 