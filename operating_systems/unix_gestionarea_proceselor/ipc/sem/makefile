CC = gcc
AR = ar
EXECUTABLES = critical_reg mmap_ex prod cons pccleanup pcinit delete
OBJECTS = pv.o sync.o pcsem.o messages.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

pv.o:pv.c pv.h ../../common/hdr.h
	$(CC) -o pv.o -c pv.c

critical_reg:critical_reg.c ../../common/err.o pv.o
	$(CC) -fPIC -o critical_reg critical_reg.c ../../common/err.o pv.o

sync.o:sync.c sync.h
	$(CC) -o sync.o -c sync.c
	
mmap_ex:mmap_ex.c sync.o ../../common/err.o
	$(CC) -fPIC -o mmap_ex mmap_ex.c sync.o ../../common/err.o

pcsem.o:pcsem.c pcsem.h ../../common/hdr.h
	$(CC) -o pcsem.o -c pcsem.c

prod:prod.c pcsem.h ../../common/hdr.h ../../common/err.o pcsem.o
	$(CC) -fPIC -o prod prod.c ../../common/err.o pcsem.o

cons:cons.c pcsem.h ../../common/hdr.h ../../common/err.o pcsem.o
	$(CC) -fPIC -o cons cons.c ../../common/err.o pcsem.o

pcinit:pcinit.c pcsem.h ../../common/hdr.h ../../common/err.o pcsem.o
	$(CC) -fPIC -o pcinit pcinit.c ../../common/err.o pcsem.o

pccleanup:pccleanup.c pcsem.h ../../common/hdr.h ../../common/err.o pcsem.o
	$(CC) -fPIC -o pccleanup pccleanup.c ../../common/err.o pcsem.o

messages.o:messages.c pv.h ../../common/hdr.h
	$(CC) -o messages.o -c messages.c

delete:delete.c messages.o ../../common/err.o pv.o
	$(CC) -fPIC -o delete delete.c messages.o ../../common/err.o pv.o
	
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
	