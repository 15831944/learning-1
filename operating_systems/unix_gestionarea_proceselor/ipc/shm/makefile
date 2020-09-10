CC = gcc
AR = ar
EXECUTABLES = shm_addr mmap_ex
OBJECTS = 
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

shm_addr:shm_addr.c ../../common/err.o
	$(CC) -fPIC -o shm_addr shm_addr.c ../../common/err.o -Wformat=0

mmap_ex:mmap_ex.c ../../common/err.o ../pipe/sync.o
	$(CC) -fPIC -o mmap_ex mmap_ex.c ../pipe/sync.o ../../common/err.o
		
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
	