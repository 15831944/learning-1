CC = gcc
AR = ar
EXECUTABLES =  echo_client_tcp echo_client_udp echod whoc whod
OBJECTS = client_proc.o socket_pasiv.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

client_proc.o:client_proc.c client_proc.h
	$(CC) -o client_proc.o -c client_proc.c

echo_client_tcp:echo_client.c client_proc.o
	$(CC) -o echo_client_tcp echo_client.c client_proc.o -DTCP

echo_client_udp:echo_client.c client_proc.o
	$(CC) -o echo_client_udp echo_client.c client_proc.o -DUDP

socket_pasiv.o:socket_pasiv.c socket_pasiv.h
	$(CC) -o socket_pasiv.o -c socket_pasiv.c

echod:echod.c socket_pasiv.o
	$(CC) -fPIC -o echod echod.c socket_pasiv.o
	
whoc:whoc.c
	$(CC) -fPIC -o whoc whoc.c
	
whod:whod.c
	$(CC) -fPIC -o whod whod.c
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
	