CC = gcc
AR = ar
EXECUTABLES = msg_client msg_server fifo_delete fifo_receive fifo_send
OBJECTS = message.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

message.o:message.c message.h
	$(CC) -o message.o -c message.c

msg_client:msg_client.c ../../common/err.o
	$(CC) -fPIC -o msg_client msg_client.c ../../common/err.o

msg_server:msg_server.c ../../common/err.o
	$(CC) -fPIC -o msg_server msg_server.c ../../common/err.o
	
fifo_delete:../fifo/fifo_delete.c message.o ../../common/err.o
	$(CC) -fPIC -o fifo_delete ../fifo/fifo_delete.c message.o ../../common/err.o

fifo_receive:../fifo/fifo_receive.c message.o ../../common/err.o ../fifo/data.h
	$(CC) -fPIC -o fifo_receive ../fifo/fifo_receive.c message.o ../../common/err.o

fifo_send:../fifo/fifo_send.c message.o ../../common/err.o ../fifo/data.h
	$(CC) -fPIC -o fifo_send ../fifo/fifo_send.c message.o ../../common/err.o 			
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
	