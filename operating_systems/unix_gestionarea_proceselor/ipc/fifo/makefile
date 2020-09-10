CC = gcc
AR = ar
EXECUTABLES = fifo_first fifo_delete fifo_receive fifo_send server_add client_add server_req client_req
OBJECTS =  message.o
OTHER_FILES = PIPE_FIFO_1 PIPE_FIFO_2 

all: $(EXECUTABLES) $(OBJECTS)

fifo_first:fifo_first.c ../../common/err.o
	$(CC) -fPIC -o fifo_first fifo_first.c ../../common/err.o

message.o:message.c message.h
	$(CC) -o message.o -c message.c

fifo_delete:fifo_delete.c message.o ../../common/err.o
	$(CC) -fPIC -o fifo_delete fifo_delete.c message.o ../../common/err.o

fifo_receive:fifo_receive.c message.o ../../common/err.o data.h
	$(CC) -fPIC -o fifo_receive fifo_receive.c message.o ../../common/err.o

fifo_send:fifo_send.c message.o ../../common/err.o data.h
	$(CC) -fPIC -o fifo_send fifo_send.c message.o ../../common/err.o

server_add:server_add.c message.o ../../common/err.o add.h
	$(CC) -fPIC -o server_add server_add.c message.o ../../common/err.o

client_add:client_add.c message.o ../../common/err.o add.h
	$(CC) -fPIC -o client_add client_add.c ../../common/err.o message.o

server_req:server_req.c ../../common/err.o packet.h
	$(CC) -fPIC -o server_req server_req.c ../../common/err.o
	
client_req:client_req.c ../../common/err.o packet.h
	$(CC) -fPIC -o client_req client_req.c ../../common/err.o
	
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
	