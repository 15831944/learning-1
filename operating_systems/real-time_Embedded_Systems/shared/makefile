CC = gcc
AR = ar
EXECUTABLES = prodcons master slave master_shm slave_shm master_sem slave_sem master_sem_shm slave_sem_shm master_slave_sem_shm
OBJECTS = 
OTHER_FILES = log.txt 

all: $(OBJECTS) $(EXECUTABLES)

prodcons:prodcons.c
	$(CC) -fPIC -o prodcons prodcons.c -lpthread

master:master.c
	$(CC) -fPIC -o master master.c

slave:slave.c
	$(CC) -fPIC -o slave slave.c

master_shm:master_shm.c
	$(CC) -fPIC -o master_shm master_shm.c -lrt

slave_shm:slave_shm.c
	$(CC) -fPIC -o slave_shm slave_shm.c -lrt

master_sem:master_sem.c
	$(CC) -fPIC -o master_sem master_sem.c -lpthread
	
slave_sem:slave_sem.c
	$(CC) -fPIC -o slave_sem slave_sem.c -lpthread
	
master_sem_shm:master_sem_shm.c
	$(CC) -fPIC -o master_sem_shm master_sem_shm.c -lpthread -lrt

slave_sem_shm:slave_sem_shm.c
	$(CC) -fPIC -o slave_sem_shm slave_sem_shm.c -lpthread -lrt

master_slave_sem_shm:master_slave_sem_shm.c
	$(CC) -fPIC -o master_slave_sem_shm master_slave_sem_shm.c -lpthread -lrt
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
	