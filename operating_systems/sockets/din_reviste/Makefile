CC = gcc

OBJECTS = utils.o tcpserver.o
EXECUTABLES = tcpserverbin
all: $(EXECUTABLES)

tcpserverbin: tcpserver.o utils.o
	$(CC) -fPIC -o tcpserverbin tcpserver.o utils.o

tcpserver.o: tcpserver.c inet.h
	$(CC) -FPIC -c -o tcpserver.o tcpserver.c
	
utils.o: utils.c inet.h
	$(CC) -fPIC -o utils.o -c utils.c

clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done