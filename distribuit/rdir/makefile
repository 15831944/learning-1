CC = gcc

EXECUTABLES = server client rdct rdst rdcu rdsu

all: $(EXECUTABLES)

#simple Read Dir client-server on TCP
server: server.c read_dir.c
	$(CC) -fPIC -o server server.c
	
client: client.c
	$(CC) -fPIC -o client client.c

#Read Dir client-server on TCP	
rdct: rdct.c rd.h
	$(CC) -fPIC -o rdct rdct.c
	
rdst:rdst.c rd.h read_dir.c
	$(CC) -fPIC -o rdst rdst.c
	
#Read Dir client-server on UDP
rdcu: rdcu.c rd.h
	$(CC) -fPIC -o rdcu rdcu.c

rdsu: rdsu.c rd.h read_dir.c
	$(CC) -fPIC -o rdsu rdsu.c
		
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 