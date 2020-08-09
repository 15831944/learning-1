CC = gcc
EXECUTABLES = onexit pthread_cleanup
OTHER_FILES = 

all: $(EXECUTABLES)

onexit: onexit.c
	$(CC) -o onexit onexit.c

pthread_cleanup: pthread_cleanup.c
	$(CC) -o pthread_cleanup pthread_cleanup.c -lpthread
	
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done