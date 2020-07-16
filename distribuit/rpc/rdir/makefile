CC = gcc
RPCGEN = rpcgen

EXECUTABLES = server client
OBJECTS = rls_clnt.c rls_svc.c rls_xdr.c rls.h
SOURCES = rls.x
all: generate $(EXECUTABLES)

generate:
	$(RPCGEN) -k $(SOURCES)
	
server: rls_svc_proc.c rls_svc.c rls_xdr.c rls.h
	$(CC) -fPIC -o server rls_svc_proc.c rls_svc.c rls_xdr.c
	
client: rls_clnt_proc.c rls_clnt.c rls_xdr.c rls.h 
	$(CC) -fPIC -o client rls_clnt_proc.c rls_clnt.c rls_xdr.c
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 