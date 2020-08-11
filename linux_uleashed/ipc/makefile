CC = gcc
EXECUTABLES = pipefile1 pipefile2 msgqueue1 msgqueue2 semaphore send receiver
OTHER_FILES = 

all: $(EXECUTABLES)

pipefile1: pipefile1.c
	$(CC) -o pipefile1 pipefile1.c

pipefile2:pipefile2.c
	$(CC) -o pipefile2 pipefile2.c

msgqueue1:msgqueue1.c
	$(CC) -o msgqueue1 msgqueue1.c
	
msgqueue2:msgqueue2.c
	$(CC) -o msgqueue2 msgqueue2.c

semaphore:semaphore.c
	$(CC) -o semaphore semaphore.c
send: send.c
	$(CC) -o send send.c
	
receiver: receiver.c
	$(CC) -o receiver receiver.c					
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	