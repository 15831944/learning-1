CC = gcc

EXECUTABLES = note_init note_svc note inotec inotes
OBJECTS =  xdr.o utils.o serverf.o
all: $(EXECUTABLES)

note_init: note_init.c note.h utils.o
	$(CC) -fPIC -o note_init note_init.c utils.o

note_svc: note_svc.c note.h xdr.o utils.o serverf.o serverf.h 
	$(CC) -fPIC -o note_svc note_svc.c xdr.o utils.o -lrpcsvc serverf.o

xdr.o: xdr.c xdr.h 
	$(CC) -fPIC -c xdr.c
	
utils.o: utils.c note.h
	$(CC) -fPIC -c utils.c
	
serverf.o: serverf.c note.h serverf.c
	$(CC) -fPIC -c serverf.c

note:note.c utils.o note.h xdr.o
	$(CC) -fPIC -o note note.c utils.o xdr.o

inotec: inotec.c utils.o note.h xdr.o
	$(CC) -fPIC -o inotec inotec.c utils.o xdr.o

inotes: inotes.c utils.o note.h xdr.o serverf.o serverf.h
	$(CC) -fPIC -o inotes inotes.c utils.o xdr.o serverf.o -lrpcsvc					
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 