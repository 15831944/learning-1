CC = gcc
#openfile and masteropenfile is not working it was ported from BSD from 1990s and is no longer available as is
OBJECTS = utils.o tcpserver.o tcpclient.o udpserver.o udpclient.o fileutil.o
EXECUTABLES = tcpserverbin tcpclientbin udpserverbin udpclientbin openfile masteropenfile

all: $(OBJECTS) $(EXECUTABLES)

masteropenfile: masteropenfile.c fileutil.o
	$(CC) -fPIC -o masteropenfile masteropenfile.c fileutil.o
	
openfile: openfile.c fileutil.o
	$(CC) -fPIC -o openfile openfile.c fileutil.o
	
tcpclientbin: tcpclient.o utils.o
	$(CC) -fPIC -o tcpclientbin tcpclient.o utils.o
	
tcpserverbin: tcpserver.o utils.o
	$(CC) -fPIC -o tcpserverbin tcpserver.o utils.o

udpserverbin: udpserver.o utils.o
	$(CC) -fPIC -o udpserverbin udpserver.o utils.o

udpclientbin: udpclient.o utils.o
	$(CC) -fPIC -o udpclientbin udpclient.o utils.o

udpclient.o: udpclient.c inet.h
	$(CC) -fPIC -c -o udpclient.o udpclient.c
	
udpserver.o: udpserver.c inet.h
	$(CC) -FPIC -c -o udpserver.o udpserver.c
		
tcpclient.o: tcpclient.c inet.h
	$(CC) -fPIC -c -o tcpclient.o tcpclient.c

tcpserver.o: tcpserver.c inet.h
	$(CC) -FPIC -c -o tcpserver.o tcpserver.c
	
utils.o: utils.c inet.h
	$(CC) -fPIC -o utils.o -c utils.c

fileutil.o: fileutil.c openfile.h
	$(CC) -fPIC -o fileutil.o -c fileutil.c

clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done